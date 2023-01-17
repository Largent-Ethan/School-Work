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
#include <time.h>

/*****************************************
 * Prints an error message and exits
*****************************************/
void error(const char* msg) {
  perror(msg);
  exit(1);
} 

/*****************************************
 * Returns an alphabetic character or a space character
*****************************************/
char rand_char() {
    int av = rand() % 27 + 65;
    if(av == 91)
        av = 32;
    return av;
}

/*****************************************
 * Prints the contents of the key to the terminal
*****************************************/
void debbug_key(char* key, int key_size) {
    fprintf(stderr, "\n\nKEY: \n");
    for(int i = 0; i < key_size + 1; i++)
        fprintf(stderr, "\t%c - %i \n",key[i], key[i]);
}

int main(int argc, char const* argv[]) {
    //Check if a size is given
    if(argc < 2) {
        error("ERROR on getting size");
        exit(1);
    }
    //Allocate a key
    int key_size = atoi(argv[1]);
    char* key = calloc(key_size + 1, sizeof(char));
    //Generate key contents
    time_t t;
    srand((unsigned)time(&t));
    for(int i = 0; i < key_size; i++)
        key[i] = rand_char();
    key[key_size] = 10;
    //Push the contents of the key to stdout
    fprintf(stdout, key);
    /***Optional***/
    //debbug_key(key, key_size);
    free(key);
}