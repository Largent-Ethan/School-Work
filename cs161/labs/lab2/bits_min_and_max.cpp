#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;



int main(){
/*---NOTES---
	srand(time(NULL));

	int x;
	cout << "Enter x: ";
	cin >> x;

	int foo = pow(x,2);
	cout << "x^2 = " << pow(x,2) << endl;
	cout << "foo = " << foo << endl;

	cout << rand()%10+1 << endl;

	return 0;
*/
	srand(time(NULL));
	
	int x;
	cout << "Enter x: ";
	cin >> x;
	
	int max = pow(2,x) - 1;
	int min = 0;
	cout << "An unsigned number with " << x << " bits has a minimum value of " << min << " and a maximum value of " << max << "." << endl;

	max = pow(2,(x-1)) - 1;
	min = (-1) * pow(2,(x-1));
	cout << "A signed number with " << x << " bits has a minimum value of " << min << " and a maximum value of " << max << "." << endl;

	return 0;
}
