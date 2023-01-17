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
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/errno.h>

#define MAXCHAR 150001
int bufferLength = 0;

/*****************************************
 * Prints an error message and exits
*****************************************/
void error(const char* msg) {
  perror(msg);
  exit(0);
}

/*****************************************
 * Sets the initial values of an address struct
*****************************************/
void initializeAddressStruct(struct sockaddr_in* address, int portNumber, char* hostname) {
  memset((char*) address, '\0', sizeof(*address));
  address->sin_family = AF_INET;
  address->sin_port = htons(portNumber);
  struct hostent* hostInfo = gethostbyname(hostname);
  if (hostInfo == NULL) 
    error("CLIENT: ERROR, no such host\n");
  memcpy((char*) &address->sin_addr.s_addr, hostInfo->h_addr_list[0], hostInfo->h_length);
}

/*****************************************
 * Concatenate the message and key into a single stringg to send
*****************************************/
char* getMessage(char* key, char* ciphertext) {
  char* myString = calloc(MAXCHAR, sizeof(char)), *tempStr_ci = calloc(MAXCHAR, sizeof(char)), *tempStr_ky = calloc(MAXCHAR, sizeof(char));
  FILE *myFile;
  int keySize, textSize;
  size_t len = MAXCHAR;
  strcpy(myString, "dec \n");
  myFile = fopen(ciphertext, "r");
  fgets(tempStr_ci, len, myFile);
  fclose(myFile);
  for (int i = 0; i < strlen(tempStr_ci); i++)
    if(tempStr_ci[i] != ' ' && (tempStr_ci[i] > 'Z' || tempStr_ci[i] < 'A'))
      if(tempStr_ci[i] != '\n') {
        fprintf(stderr, "Error: The ciphertext has an invalid char in it at char [%i]:\"%c\" \n", i, tempStr_ci[i]);
        exit(1);
      }
  textSize = strlen(tempStr_ci);
  strcat(myString, tempStr_ci);
  bufferLength = strlen(tempStr_ci);
  strcat(myString, "\n");
  myFile = fopen(key, "r");
  fgets(tempStr_ky, len, myFile);
  fclose(myFile);
  for (int i = 0; i < strlen(tempStr_ky); i++)
    if(tempStr_ky[i] != ' ' && (tempStr_ky[i] > 'Z' || tempStr_ky[i] < 'A'))
      if(tempStr_ky[i] != '\n') {
        fprintf(stderr, "Error: The key has an invalid char in it at char [%i] \n", i);
        exit(1);
      }
  keySize = strlen(tempStr_ky);
  strcat(myString, tempStr_ky);
  strcat(myString, "\n end \n");
  if (keySize < textSize) {
    fprintf(stderr, "Error: The key is shorter than the text size.\n");
    exit(1);
  }
  return(myString);
}

/*****************************************
 * Send the message to the server to be  decrypted
*****************************************/
int sendMessage(int socketFD, char* buffer) {
  int charsWritten;
  charsWritten = send(socketFD, buffer, strlen(buffer), 0);
  if (charsWritten < 0)
    error("CLIENT: ERROR writing to socket");
  if (charsWritten < strlen(buffer))
    printf("CLIENT: WARNING: Not all data written to socket!\n");
  return(charsWritten);
}

/*****************************************
 * Recieve a messsage from the server
*****************************************/
void readMessage(int socketFD, char* buffer, int bufferLen) {
  int charsRead = 0, sizeLeft = bufferLen, i;
  char* tempStr = calloc(MAXCHAR, sizeof(char));
  memset(buffer, '\0', MAXCHAR);
  while (strstr(buffer,"\n end \n") == NULL) {
    memset(tempStr, '\0', strlen(tempStr));
    errno = 0;
    charsRead = recv(socketFD, tempStr, sizeof(tempStr), 0);
    if (charsRead < 0)
      error("SERVER: ERROR reading from socket");
    if (buffer[0] == '\0')
      strcpy(buffer, tempStr);
    else
      strcat(buffer, tempStr);
  }
  fflush(stdout);
  buffer = strtok(buffer, "\n");
  printf("%s\n",buffer);
}


int main(int argc, char* argv[]) {
  int socketFD, portNumber, charsWritten, charsRead;
  struct sockaddr_in serverAddress;
  char buffer[MAXCHAR], key[MAXCHAR], tempStr[MAXCHAR];
  memset(buffer, '\0', strlen(buffer));
  if (argc < 3) {
    fprintf(stderr,"USAGE: %s  port\n", argv[0]);
    exit(0);
  }
  socketFD = socket(AF_INET, SOCK_STREAM, 0);
  if (socketFD < 0)
    error("CLIENT: ERROR opening socket");
  initializeAddressStruct(&serverAddress, atoi(argv[3]), "localhost");
  if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    error("CLIENT: ERROR connecting");
  strcpy(buffer, getMessage(argv[2], argv[1]));
  int bufferLen = sendMessage(socketFD, buffer);
  readMessage(socketFD, buffer, MAXCHAR);
  close(socketFD);
  return 0;
}