#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>


using namespace std;


int main() {
//Variable Declarations
	bool run = true;	//Run the code
	bool valid = false;	//Valid input to get password
	int len;		//Length of the password
	int let;		//Yes or no to letters
	int ulet;		//Yes or no to uppercase letters
	int n_ulet = 0;		//Number of uppercase letters
	int llet;		//Yes or no to lowercase letters
	int n_llet = 0;		//Number of lowercase letters
	int num;		//Yes or no to numbers
	int n_num = 0;		//Number of numbers
	int type;		//Type of character
	char _char;		//Character
	int re_run;		//Re-run the code

//Introduction
	cout << "\n--- Welcome to the Amazing Password Creator! ---" << endl;	

	srand(time(NULL));

	while (run==true) {
//Gathering and Checking Input
		while (1) {
	//How long?
			cout << "\n\n    How long would you like your password to be? : ";
			cin >> len;
			if (len==0) {
				cout << "\nError: Invalid | Password cant be empty\n";
				break;
			}
			if (len<0) {
				cout << "\nError: Invalid | That is not a real length\n";
				break;
			}
	//Letters?
			cout << "    Do you want any letters in it? | 0-no | 1-yes :  ";
			cin >> let;
			if (let!=0 and let!=1) {
				cout << "\nError: Invalid | Its a yes or no answer\n";
				break;
			}
			if (let==1) {
		//Uppercase letters?
				cout << "    Do you want any upppercase letters in it? | 0-no | 1-yes :  ";
				cin >> ulet;
				if (ulet!=0 and ulet!=1) {
					cout << "\nError: Invalid | Its a yes or no answer\n";
					break;
				}
			//How many uppercase letters?
				if (ulet==1) {		
					cout << "    How many uppercase letters do you want? : ";
					cin >> n_ulet;
					if (n_ulet==0) {
						cout << "Error: Invalid | You said you wanted uppercase letters\n";
						break;
					}
					if (n_ulet<0) {
						cout << "\nError: Invalid | That is not a real amount\n";
						break;
					}
					if (n_ulet>len) {
						cout << "\nError: Invalid | Amount of characters exceeds the length\n";
						break;
					}
				}
		//Lowercase letters?
				cout << "    Do you want any lowercase letters in it? | 0-no | 1-yes :  ";
				cin >> llet;
				if (llet!=0 and llet!=1) {
					cout << "\nError: Invalid | Its a yes or no answer\n";
					break;
				}
			//How many lowercase letters?	
				if (llet==1) {		
					cout << "    How many lowercase letters do you want? : ";
					cin >> n_llet;
					if (n_llet==0) {
						cout << "\nError: Invalid | You said you wanted lowercase letters\n";
					break;
					}
					if (n_llet<0) {
						cout << "\nError: Invalid | That is not a real amount\n";
						break;
					}
					if ((n_ulet + n_llet)>len) {
						cout << "\nError: Invalid | Amount of characters exceeds the length\n";
						break;
					} 
				}
				if (llet==0 and ulet==0) {
					cout << "\nError: Invalid | You said you wanted letters\n";
					break;
				}
			}
	//Numbers?
			cout << "    Do you want any numbers in it? | 0-no | 1-yes :  ";
			cin >> num;
			if (num!=0 and num!=1) {
				cout << "\nError: Invalid | Its a yes or no answer\n";
				break;
			}
			if (num==1) {
				cout << "    How many numbers do you want? : ";
				cin >> n_num;
				if (n_num==0) {
					cout << "\nError: Invalid | You said you wanted numbers\n";
					break;
				}
				if (n_num<0) {
					cout << "\nError: Invalid | That is not a real amount\n";
					break;
				}
			}
			if ((n_ulet + n_llet + n_num)>len) {
				cout << "\nError: Invalid | Amount of characters exceeds the length\n";
				break;
			}
			if ((n_ulet + n_llet + n_num)<len) {
				cout << "\nError: Invalid | Amount of characters is less than the length\n";
				break;
			} 
			valid = true;
			break;
		}
//Password generator
		if (valid==true) {
			cout << "\n\n    Your random password is: ";
			for (int i = 0; i < len; ++i) {
	//Randomizing the type of character
				if (n_llet>0 and n_ulet>0 and n_num>0) {
					type = rand() % 3;
				}
				if (n_llet>0 and n_ulet>0 and n_num==0) {
					type = rand() % 2;
				}
				if (n_llet>0 and n_ulet==0 and n_num>0) {
					type = rand() % 2;
					if (type==1) {
						type = 2;
					}
				}
				if (n_llet==0 and n_ulet>0 and n_num>0) {
					type = rand() % 2 + 1;
				}
				if (n_llet>0 and n_ulet==0 and n_num==0) {
					type = 0;
				}
				if (n_llet==0 and n_ulet>0 and n_num==0) {
					type = 1;
				}
				if (n_llet==0 and n_ulet==0 and n_num>0) {
					type = 2;
				}
	//Randomizing the character
				if (type==0) {
					_char = (char) (rand() % 26 + 97);
					n_llet = n_llet - 1;
				}
				if (type==1) {
					_char = (char) (rand() % 26 + 65);
					n_ulet = n_ulet - 1;
				}
				if (type==2) {
					_char = (char) ( rand() % 10 + 48);
					n_num = n_num - 1;
				}
	//Printing the character
				cout << _char;
			}
		}
//Asking to run program again
		while(1) {
			cout << "\n\n    Would you like to generate another password? | 0-no | 1-yes : ";
			cin >> re_run;
			if (re_run!=0 and re_run!=1) {
				cout << "\nError: Invalid | Its a yes or no answer";
			}
			if (re_run==0) {
				run=false;
				break;
			}
			if (re_run==1) {
				run=true;
				break;
			}
		}
	}
}
