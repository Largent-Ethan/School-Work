#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;



int main() {

	srand(time(NULL));

//Variable Declarations	
	float Monthly_Salary;
	int Months;
	float Car_Cost;
	int Cars_Sold;
	int Misconducts;
	int Tax_Year;
	char State;
	float Gross_Income;
	float Profit;
	float Average_Car_Sell_Price;
	float Taxes;
	float Remaining_Income;
//integers can still be inputed as strings and when they are things break?

//Getting Input Starts
	//Entering Monthly Salary
	cout << "Enter your monthly salary: ";
	cin >> Monthly_Salary;

	while(1) {
		if (cin.fail() or !(Monthly_Salary>0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');//Copy pasted
			cout << "Invalid Input\nEnter your monthly salary: ";
			cin >> Monthly_Salary;
		}
		else
			break;
	}
	
	//Entering Months
	cout << "Enter number of months you worked in the past year: ";
	cin >> Months;
	
	while(1) {
		if (cin.fail() or Months<0 or Months>12) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid Input\nEnter number of months you worked in the past year: ";
			cin >> Months;
		}
		else
			break;
	}

	//Entering Car Cost
	cout << "Enter the cost of the car: ";
	cin >> Car_Cost;
	
	while(1) {
		if (cin.fail() or !(Car_Cost>0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid Input\nEnter the cost of the car: ";
			cin >> Car_Cost;
		}
		else
			break;
	}

	//Entering Cars Sold
	cout << "Enter number of cars you've sold in the past year: ";
	cin >> Cars_Sold;
	
	while(1) {
		if (cin.fail() or !(Cars_Sold>-1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid Input\nEnter number of cars you've sold in the past year: ";
			cin >> Cars_Sold;
		}
		else
			break;
	}

	//Entering Misconducts
	cout << "Enter number of misconducts observed in the past year: ";
	cin >> Misconducts;
	
	while(1) {
		if (cin.fail() or !(Misconducts>-1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid Input\nEnter number of misconducts observed in the past year: ";
			cin >> Misconducts;
		}
		else
			break;
	}

	//Entering Tax Year
	cout << "Which tax year are you in, enter 1 for 2017, 2 for 2018: ";
	cin >> Tax_Year;
	
	while(1) {
		if (cin.fail() or Tax_Year>2 or Tax_Year<1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid Input\nWhich tax year are you in, enter 1 for 2017, 2 for 2018: ";
			cin >> Tax_Year;
		}
		else
			break;
	}

	//Entering State
	cout << "Which state are you in, enter A, B, or C: ";
	cin >> State;
	
	while(1) {
		if (cin.fail() or (State!='A' and State!='B' and State!='C' and State!='a' and State!='b' and State!='c')) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid Input\nWhich state are you in, enter A, B, or C: ";
			cin >> State;
		}
		else
			break;
	}
//Getting Input Stops

//Calculating Output Starts
	//Calculate Profit
	Profit = ((rand() % 6) + 5) *  Car_Cost / 100 * Cars_Sold;
	
	//Calculate Average Car Sell Price
	Average_Car_Sell_Price = Car_Cost + Profit / Cars_Sold;
	
	//Calculate Gross Income
	Gross_Income = Monthly_Salary * Months + 0.02 * Profit;
	if (Misconducts!=0)
		Gross_Income = Gross_Income - (100 * pow(2, Misconducts - 1));

	//Calculate Taxes
	if (Tax_Year==1) {
		if (State=='A' or State=='a')
			Taxes = Gross_Income * 0.06;
		if (State=='B' or State=='b') {
			if (Gross_Income<2000)
				Taxes = 0;
			else if (Gross_Income<10000)
				Taxes = 100;
			else
				Taxes = Gross_Income * 0.1 + 100;
		}
		if (State=='C' or State=='c') {
			if (Gross_Income<3500)
				Taxes = Gross_Income * 0.05;
			else if (Gross_Income<9000)
				Taxes = Gross_Income * 0.07 + 175;
			else if (Gross_Income<120000)
				Taxes = Gross_Income * 0.09 + 560;
			else
				Taxes = Gross_Income * 0.09 + 11000;
		}
	}
	
	if (Tax_Year==2) {
		if (State=='A' or State=='a')
			Taxes = Gross_Income * 0.08;
		if (State=='B' or State=='b') {
			if (Gross_Income<2500)
				Taxes = 0;
			else if (Gross_Income<10000)
				Taxes = 115;
			else
				Taxes = Gross_Income * 0.105 + 115;
		}
		if (State=='C' or State=='c') {
			if (Gross_Income<3450)
				Taxes = Gross_Income * 0.05;
			else if (Gross_Income<8700)
				Taxes = Gross_Income * 0.07 + 172.5;
			else if (Gross_Income<125000)
				Taxes = Gross_Income * 0.09 + 540;
			else
				Taxes = Gross_Income * 0.099 + 11007;
		}
	}

	//Calculate Remaing Income
	Remaining_Income = Gross_Income - Taxes;
//Getting Output Stops

//Output
	cout << "\nThe average selling price, generated randomly, is $" << Average_Car_Sell_Price << ", you will earn 2% of the profit, which is $" << Profit << ".\n\nThe gross income is: $" << Gross_Income << "\nThe tax you need to pay is: $" << Taxes << "\nRemaining: $" << Remaining_Income << endl;

	return 0;

}
