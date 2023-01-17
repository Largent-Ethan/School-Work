/******************************************************************************
 * Assignment 5: One-Time Pads
 * Name: Ethan Largent
 * Class: Operating Systems 1 - Benjamin Brewster
 * Due date: 12/7/2022
 * Description: Mimics the behavior of two clients encrypting and decrypting
 * messages using a One-Time pad system
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/errno.h>

#define MAXCHAR 150001


/*****************************************
 * Prints an error message and exits
*****************************************/
void error(const char* msg) {
  perror(msg);
  exit(1);
}

/*****************************************
 * Sets the initial values of an address struct
*****************************************/
void initializeAddressStruct(struct sockaddr_in* address, int portNumber) {
   memset((char*) address, '\0', sizeof(*address));
   address->sin_family = AF_INET;
   address->sin_port = htons(portNumber);
   address->sin_addr.s_addr = INADDR_ANY;
}

/*****************************************
 * Return an decrypted message using the encrypted message and key found in the buffer
*****************************************/
char* decryptMessage(char* buffer) {
  int a = 0, b = 0;
  char* key = calloc(MAXCHAR + 1, sizeof(char)), *verDec = calloc(MAXCHAR + 1, sizeof(char)), *toDecrypt = calloc(MAXCHAR + 1, sizeof(char));
  verDec = strtok(buffer,"\n");
  if (strcmp(verDec,"dec ") != 0)
    return("You are not allowed to connect to the wrong client\n end \n");
  toDecrypt = strtok(NULL,"\n" );
  key = strtok(NULL,"\n" );
  for (size_t i = 0; i < strlen(toDecrypt); i++) {//Decrypt each character of the message
    a = toDecrypt[i];
    if (a == 32)
      a = 91;
    b = key[i];
    if (b == 32)
      b = 91;
    a = abs(a) - 65;
    b = abs(b) - 65;
    a -= b;
    if (a < 0 )
      a += 27;
    a = a % 27;
    if((a + 65) > 90 || (a + 65) < 65)
      a = 32 - 65;
    toDecrypt[i] = a + 65;
  }
  strcat(toDecrypt, "\n end \n");
  return(toDecrypt);
}


int main(int argc, char* argv[]) {
  int connectionSocket, charsRead;
  char buffer[MAXCHAR], key[MAXCHAR], tempStr[MAXCHAR];
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t sizeOfClientInfo = sizeof(clientAddress);
  if (argc < 2) {
    fprintf(stderr,"USAGE: %s port\n", argv[0]);
    exit(1);
  }
  int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (listenSocket < 0)
    error("ERROR opening socket");
  initializeAddressStruct(&serverAddress, atoi(argv[1]));
  if (bind(listenSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    error("ERROR on binding");
  listen(listenSocket, 5);
  while(1) {
    connectionSocket = accept(listenSocket, (struct sockaddr *)&clientAddress, &sizeOfClientInfo);
    if (connectionSocket < 0)
	    error("ERROR on accept");
    pid_t spawnpid = -69;
    int childpid = 0, childstatus = 0;
    spawnpid = fork();
    switch(spawnpid) {
	    case -1:
	      perror("fork is a no go");
	      break;
	    case 0:
	      memset(buffer, '\0', strlen(buffer));
	      while (strstr(buffer," end ") == NULL) {
          memset(tempStr, '\0', strlen(tempStr));
	        errno = 0;
	        charsRead = recv(connectionSocket, tempStr, sizeof(tempStr), 0);
	        if (charsRead < 0)
		        error("SERVER: ERROR reading from socket");
	        if (buffer[0] == '\0')
		        strcpy(buffer, tempStr);
	        else
		        strcat(buffer, tempStr);
	      }
        fflush(stdout);
	      strcpy(buffer,decryptMessage(buffer));
        fflush(stdout);
        int sizeLeft = strlen(buffer), charsSent = 0, i = 0;
	      while (i < strlen(buffer)) {
	        charsSent = send(connectionSocket, buffer, sizeLeft , 0);
          if (charsSent < 0)
            error("ERROR writing to socket");
	        i += charsSent;
	        sizeLeft -= charsSent;
	      }
	      close(connectionSocket);
        break;
      default:
        waitpid(spawnpid, &childstatus, 1);
        break;
    }
  }
  close(listenSocket);
  return 0;
}