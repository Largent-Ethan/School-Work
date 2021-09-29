#include <iostream>
#include <string>

using namespace std;

void swap_sentence(string sen1, string sen2){
   string x;
   x = sen1;
   sen1 = sen2;
   sen2 = x;
   cout << "In swap function ..." << endl;
   cout << "sen1: " << sen1 << endl;
   cout << "sen2: " << sen2 << endl;
}

int main(){
   string sentence1, sentence2;
   cout << "Enter sentence 1: ";
   getline(cin, sentence1);
   cout << "Enter sentence 2: ";
   getline(cin, sentence2);
   swap_sentence(sentence1, sentence2);
   cout << "In main function ..." << endl;
   cout << "sentence1: " << sentence1 << endl;
   cout << "sentence2: " << sentence2 << endl;
   return 0;
}
