/******************************************************************************
 * Assignment: Assignment 1: Movies
 * Name: Ethan Largent
 * Class: Operating Systems 1 with Benjamin Brewster
 * Due date: 10/10/2022
 * Description: Reads a formatted file containing movie data
 *              Stores the data in a linked list of movie structs
 *              Prompts the user with operations to enact on the movie data
******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*From Data Structures*/ struct link {
/*From Data Structures*/   void* val;
/*From Data Structures*/   struct link* next;
/*From Data Structures*/ };
/*From Data Structures*/ 
/*From Data Structures*/ struct list {
/*From Data Structures*/   struct link* head;
/*From Data Structures*/ };
/*From Data Structures*/ 
/*From Data Structures*/ struct list* list_create() {
/*From Data Structures*/   struct list* list = malloc(sizeof(struct list));
/*From Data Structures*/   list->head = NULL;
/*From Data Structures*/   return list;
/*From Data Structures*/ }
/*From Data Structures*/ 
/*From Data Structures*/ void list_free(struct list* list) {
/*From Data Structures*/   if(list->head != NULL){
/*From Data Structures*/     struct link* nx_ptr = list->head->next;
/*From Data Structures*/     while(list->head->next != NULL){
/*From Data Structures*/       free(list->head);
/*From Data Structures*/       list->head = nx_ptr;
/*From Data Structures*/       nx_ptr = list->head->next;
/*From Data Structures*/     }
/*From Data Structures*/     free(list->head);
/*From Data Structures*/   }
/*From Data Structures*/   free(list);
/*From Data Structures*/   return;
/*From Data Structures*/ }
/*From Data Structures*/ 
/*From Data Structures*/ void list_insert(struct list* list, void* val) {
/*From Data Structures*/   struct link* hd_ptr = list->head;
/*From Data Structures*/   list->head = malloc(sizeof(struct link));
/*From Data Structures*/   list->head->val = val;
/*From Data Structures*/   list->head->next = hd_ptr;
/*From Data Structures*/   return;
/*From Data Structures*/ }

/*************************************
 * Movie struct
 ************************************/
struct movie {
  char* title;
  int year;
  char languages[5][20];
  float ratingValue;
};

/*************************************
 * Assigns values to a dynamically allocated movie struct and returns its address
 ************************************/
struct movie* create_movie(char* t, int y, char l[5][20], float rv) {
  struct movie *new_movie = malloc(sizeof(struct movie));
  new_movie->title = t;
  new_movie->year = y;
  for(int i = 0; i < 5; i++)
    strcpy(new_movie->languages[i], l[i]);
  new_movie->ratingValue = rv;
  return new_movie;
}

/*************************************
 * Frees the allocated memory used by a movie struct
 ************************************/
void movie_free(struct movie* m){
  free(m->title);
  free(m);
  return;
}

/*************************************
 * Processes a formatted string and passes the found values into creating a movie struct and adds it to the given linked list
 ************************************/
void read_line(struct list *d, char* l) {
  //initialize variables for movie creation
  int n = 0, y;
  float rv;
  char lan[6][20];
  for(int i = 0; i < 6; i++)
    memset(lan[i], '\0', 20);
  //get title from line
  char *token = strtok(l, "[],;");
  char *t = calloc(strlen(token), sizeof(char));
  strcpy(t, token);
  //get year from line
  token = strtok(NULL, "[],;");
  y = atoi(token);
  //get languages from line
  while(1){
    token = strtok(NULL, "[],;");
    if(token == NULL)
      break;
    strcpy(lan[n], token);
    n++;
  }
  //get rating value from line (more specifically from the last language and clear the last language)
  rv = atof(lan[n - 1]);
  strcpy(lan[n - 1], "");
  //create movie
  list_insert(d, create_movie(t, y, lan, rv));
  return;
}

/*************************************
 * Processes a formatted file and reads it line by line to fill in a linked list with movie data
 ************************************/
int read_file(FILE* inf, struct list* out) {
  int n;
  char currl[256];
  fgets(currl, 256, inf);
  memset(currl, '\0', 256);
  while(fgets(currl, 256, inf) != NULL) {
    printf("%s", currl);
    read_line(out, currl);
    memset(currl, '\0', 256);
    n++;
  }
  return n;
}

/*************************************
 * Prints all movies matching a given year from a list of movies
 ************************************/
void print_movies_from_year(struct list *d, int s) {
  struct movie* currm;
  struct link* curr = d->head;;
  int input;
  printf("Enter the year for which you want to see movies: ");
  scanf("%d", &input);
  int found = 0;
  for(int i = 0; i < s; i++){
    currm = (struct movie*)(curr->val);
    if(currm->year == input){
      found = 1;
      printf("%s\n", currm->title);
    }
    curr = curr->next;
  }
  if(found == 0)
    printf("No data about movies released in the year %i\n", input);
}

/*************************************
 * Prints the highest rated movies from each year from a list of movies
 ************************************/
void print_highest_rated_movies(struct list *d, int s) {
  struct movie* currmi;
  struct movie* currmj;
  struct link* curri = d->head;;
  struct link* currj;

  int found, fyrss = 0;
  int fyrs[s];
  for(int i = 0; i < s; i++){
    found = 0;
    currmi = (struct movie*)(curri->val);
    for(int i = 0; i < fyrss; i++)
      if(currmi->year == fyrs[i]){
        found = 1;
        break;
      }
    if(found == 0){
      currj = curri->next;
      for(int j = i + 1; j < s; j++){
        currmj = (struct movie*)(currj->val);
        if(currmi->ratingValue < currmj->ratingValue && currmi->year == currmj->year)
          currmi = currmj;
        currj = currj->next;
      }
    }
    if(found == 0){
      printf("%i %1.1f %s\n", currmi->year, currmi->ratingValue, currmi->title);
      fyrs[fyrss] = currmi->year;
      fyrss++;
    }
    curri = curri->next;
  }
}

/*************************************
 * Prints all movies matching a given language from a list of movies
 ************************************/
void print_movies_from_language(struct list *d, int s) {
  struct movie* currm;
  struct link* curr = d->head;
  char input[20];
  int found = 0;
  printf("Enter the language for which you want to see movies: ");
  scanf("%s", &input);
  for(int i = 0; i < s; i++){
    currm = (struct movie*)(curr->val);
    for(int j = 0; j < 5; j++)
      if(0 == strcmp((currm->languages)[j], input)){
        found = 1;
        printf("%4i %s\n", currm->year, currm->title);
        break;
      }
    curr = curr->next;
  }
  if(found == 0)
    printf("No data about movies released in %s\n", input);
}


int main(int argc, char const* argv[]) {
  //read file
  char infstr[50];
  strcpy(infstr, argv[1]);
  FILE *inFile = fopen(infstr, "r");
  struct list* movieData = list_create();
  int numMovies = read_file(inFile, movieData);
  fclose(inFile);
  printf("Processed file %s and parsed data for %d movies\n", infstr, numMovies);
  //user interface
  int input;
  while(1){
    printf("\n\n1. Show movies released in the specified year\n2. Show highest rated movie for each year\n3. Show the title and year of release of all movies in a specific language\n4. Exit from the program\n\nEnter a choice from 1 to 4: ");
    scanf("%d", &input);
    if(input == 1){
      print_movies_from_year(movieData, numMovies);
    } else if(input == 2){
      print_highest_rated_movies(movieData, numMovies);
    } else if(input == 3){
      print_movies_from_language(movieData, numMovies);
    } else if(input == 4){
      break;
    } else{
      printf("\nYou entered an incorrect choice! Try again\n");
    }
  }
  //free memory
  struct link *temp = movieData->head;
  while(temp != NULL){
    movie_free(temp->val);
    temp = temp->next;
  }
  list_free(movieData);
  return 0;
}