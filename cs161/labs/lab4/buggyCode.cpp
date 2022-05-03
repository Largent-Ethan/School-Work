/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>

using namespace std;

int main(){

	int x=3;
	int y;
	char  myAnswer;
	bool again;
	int num;

	y = x;
	cout << "y is set to: " << y << endl;
	again = true;
//X greater than 3
	while(again){
		cout << "Please input a number for x: ";
		cin >> x;
		if(x > y) {
			cout << "X is greater than Y\n";
			cout << "would you like to input another number? | 0-no 1-yes" << endl;
			cin >> again;
		}
		else{
			cout << "X is less than or equal to Y" << endl;
			cout << "would you like to input another number? | 0-no 1-yes" << endl;
			cin >> again;
		}
	}
//Count to 10?
	for(int x = 0; x < 10; ++x) {
		cout << x << endl;
	}
//Factorial
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
	for(int x = num; x > 1; --x)
		num = num *(x-1);
	cout << num << endl;
//Are you enjoying class?
	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer == 'y')
		cout << "YAY" << endl;
	else
		cout << "YOU WILL SOON!" << endl;

	return 0;
}
