#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main(){
//Task 1
   char cstr[100];

   cout << "Enter sentence: ";
   cin.getline(cstr, 100);

   cout << cstr << endl;

//Task 2
   int num_words;

   cout << "How many words to search: ";
   cin >> num_words;

   string wrdarr[num_words];
   string blah;

   getline(cin, blah);

   for(int i=0; i < num_words; i++){
      cout << "Enter a word: ";
      getline(cin, wrdarr[i]);
   }

   return 0;
}
