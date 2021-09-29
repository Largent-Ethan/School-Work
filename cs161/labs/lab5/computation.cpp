#include <iostream>

using namespace std;

float liter_input();
float mile_input();

int main (){
   int run;
   float car1_liters, car1_miles, car1_miles_per_gallon, car2_liters, car2_miles, car2_miles_per_gallon;
   cout << "\nHow many liters of gasoline did car 1 consume? | ";
   cin >> car1_liters;
   cout << "\nHow many miles did car 1 drive? | ";
   cin >> car1_miles;
   cout << "\nHow mant liters of gasoline did car 2 consume? | ";
   cin >> car2_liters;
   cout << "\nHow many liters of gasoline did car 2 consume? | ";
   cin >> car2_miles;
   car1_miles_per_gallon = car1_miles / (car1_liters * 0.264179);
   car2_miles_per_gallon = car2_miles / (car1_liters * 0.264179);
   cout << "\nCar 1 gets " << car1_miles_per_gallon << " miles per a gallon.\nCar 2 gets " << car2_miles_per_gallon << " miles per a gallon.\n";
   if (car1_miles_per_gallon>car2_miles_per_gallon)
      cout << "Car 2 has the best fuel efficiency.\n";
   else if (car1_miles_per_gallon<car2_miles_per_gallon)
      cout << "Car 1 has the best fuel efficiency.\n";
   else
      cout << "The cars have the same fuel efficiency.\n";
   cout << "\nWould you like to enter another pair of cars? | 1-yes  0-no";
   cin >> run;
   if (run==1)
      return main();
   return 0;
}
