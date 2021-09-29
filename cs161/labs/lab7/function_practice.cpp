#include <iostream>
#include <stream>

using namespace std;

void get_string(string*);
void set_replace_string(string, string*);
int get_seach_replace(char, string, string&);

int main(){
   string sentence, sentence_copy;
   char letter;

   get_string(&sentence);
   sentence_copy = sentence;
   set_replace_string(sentence, &sentence_copy);
   get_search_replace(letter, sentence, sentence_copy)

   return 0;
}

/************************************************************************
 * ** Function: get_string
 ** Desciption: 
 ** Parameteres: 
 ** Pre-Conditions: 
 ** Post-Conditions: 
************************************************************************/
void get_string(string* sentence){
   getline(sin, *sentence)
}

/************************************************************************
 * ** Function: 
 ** Desciption: 
 ** Parameteres: 
 ** Pre-Conditions: 
 ** Post-Conditions: 
*****************************************************/
void set_replace_string(string sentence, string* sentence_copy){
   for (int i = 0; i < sentence.length(); i++)
      if (sentence[i] != ' ')
	 *sentence_copy[i] = '_';
}

/*******************************************
 * ** Function: 
 ** Desciption: 
 ** Parameteres: 
 ** Pre-Conditions: 
 ** Post-Conditions: 
*******************************************/
int get_seach_replace(char letter, string sentence, string& sentence_copy){
   int counter;
   for (int i = 0; i < sentence.length(); i++)
      if (sentence[i] == letter) {
	 sentence_copy[i] = letter;
	 counter++;
      }
   return counter;
}

