/******************************************************************************
 * Assignment: Assignment 2: Movies
 * Name: Ethan Largent
 * Class: Operating Systems 1 with Benjamin Brewster
 * Due date: 10/10/2022
 * Description: Reads a formatted file containing movie data
 *              Stores the data in a linked list of movie structs
 *              Organizes the movie data into a directory containing multiple files
******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

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
    read_line(out, currl);
    memset(currl, '\0', 256);
    n++;
  }
  return n;
}

/*************************************
 * Returns the largest file in the current directory
 ************************************/
void get_largest_file(char* fn) {
  DIR *currDir = opendir(".");
  struct dirent *aDir;
  off_t fs = 0;
  struct stat dirStat;
  int i = 0;
  //look at all files in current directory
  while((aDir = readdir(currDir)) != NULL) {
    if(strrchr(aDir->d_name, '.'))
      if(strncmp("movies_", aDir->d_name, 6) == 0 && strncmp(".csv\0", strrchr(aDir->d_name, '.'), 5) == 0) {
        stat(aDir->d_name, &dirStat);
        if(i==0 || dirStat.st_size > fs){
          fs = dirStat.st_size;
          memset(fn, '\0', sizeof(fn));
          strcpy(fn, aDir->d_name);
        }
        i++;
      }
  }
  closedir(currDir);
  return;
}

/*************************************
 * Returns the smallest file in the current directory
 ************************************/
void get_smallest_file(char* fn) {
  DIR *currDir = opendir(".");
  struct dirent *aDir;
  off_t fs = 1000000;
  struct stat dirStat;
  int i = 0;
  //look at all files in current directory
  while((aDir = readdir(currDir)) != NULL) {
    if(strrchr(aDir->d_name, '.'))
      if(strncmp("movies_", aDir->d_name, 6) == 0 && strncmp(".csv\0", strrchr(aDir->d_name, '.'), 5) == 0) {
        stat(aDir->d_name, &dirStat);
        if(i==0 || dirStat.st_size < fs){
          fs = dirStat.st_size;
          memset(fn, '\0', sizeof(fn));
          strcpy(fn, aDir->d_name);
        }
        i++;
      }
  }
  closedir(currDir);
  return;
}

/*************************************
 * Creates a movie file in the given directory using the data in the given in the list
 ************************************/
void create_movie_file(char* dirn, struct list *d, int yr, int s){
  //create file name and the file
  char yrstr[4];
  sprintf(yrstr, "%d", yr);
  char fn[256];
  memset(fn, '\0', sizeof(fn));
  strcat(fn, "./");
  strcat(fn, dirn);
  strcat(fn, "/");
  strcat(fn, yrstr);
  strcat(fn, ".txt");
  FILE *newFile = fopen(fn, "w");
  chmod(fn, 0640);
  //fill file with movies from the year
  struct movie* currm;
  struct link* curr = d->head;
  for(int i = 0; i < s; i++){
    currm = (struct movie*)(curr->val);
    if(currm->year == yr)
      fprintf(newFile, "%s\n", currm->title);
    curr = curr->next;
  }
  fclose(newFile);
  return;
}

/*************************************
 * Prints all movies matching a given year from a list of movies
 ************************************/
char* process_data(struct list *d, int s, char* dirn) {
  //get array of years in file;
  struct movie* currm;
  struct link* curr = d->head;
  int found, fyrss = 0;
  int fyrs[s];
  for(int i = 0; i < s; i++){
    found = 0;
    currm = (struct movie*)(curr->val);
    for(int i = 0; i < fyrss; i++)
      if(currm->year == fyrs[i]){
        found = 1;
        break;
      }
    if(found == 0){
      fyrs[fyrss] = currm->year;
      fyrss++;
    }
    curr = curr->next;
  }
  //generate directory and fill with files for each year
  char dirnums[6];
  srand(time(0));
  sprintf(dirnums, "%d", rand() % 100000);
  getlogin_r(dirn, 63);
  strcat(dirn, ".movies.");
  strcat(dirn, dirnums);
  mkdir(dirn, 0750);
  for(int i = 0; i < fyrss; i++)
    create_movie_file(dirn, d, fyrs[i], s);
  return dirn;
}


int main() {
  int iinput = 0, numMovies;
  char infstr[50], dirname[50];
  while(1) {

    //user interface - main menu
    while(1) {
      printf("\n1. Select file to process\n2. Exit the program\n\n Enter a choice 1 or 2: ");
      scanf("%d", &iinput);
      if(iinput == 1 || iinput == 2)
        break;
      else
        printf("You entered an incorrect choice! Try again\n");
    }
    if(iinput == 2)
      break;

    //user interface - file selection
    while(1) {
      printf("\nWhich file you want to process?\nEnter 1 to pick the largest file\nEnter 2 to pick the smallest file\nEnter 3 to specify the name of a file\n\nEnter a choice from 1 to 3: ");
      scanf("%d", &iinput);
      if(iinput == 1) {
        get_largest_file(infstr);
        break;
      } else if(iinput == 2) {
        get_smallest_file(infstr);
        break;
      } else if(iinput == 3) {
        printf("Enter the complete file name: ");
        scanf("%s", infstr);
        if(fopen(infstr, "r"))
          break;
        printf("The file %s was not found! Try again\n", infstr);
      } else
        printf("You entered an incorrect choice! Try again\n");
    }

    //process file
    printf("Now processing the chosen file named %s\n", infstr);
    FILE *inFile = fopen(infstr, "r");
    struct list* movieData = list_create();
    numMovies = read_file(inFile, movieData);
    fclose(inFile);
    process_data(movieData, numMovies, dirname);
    printf("Created directory with name %s\n", dirname);
    
    //free memory
    struct link *temp = movieData->head;
    while(temp != NULL){
      movie_free(temp->val);
      temp = temp->next;
    }
    list_free(movieData);
  }
  return 0;
}