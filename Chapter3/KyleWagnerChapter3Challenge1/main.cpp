/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 3 Challenge 1
 *  Miles per Gallon: Write a program that calculates a car's gas mileage. 
 *  The program should ask the user to enter the number of gallons of gas the 
 *  car can hold, and the number of miles it can be driven on a full tank. 
 *  It should then display the number of miles that may be driven per gallon 
 *  of gas.
 */

# include <iostream>
using namespace std;

int main() {
    // initialize variables
    double fuel_capacity, max_range, miles_per_gallon;
    
    // ask user for car fuel capacity and max range
    cout << "How many gallons of gas does your car hold?" << endl;
    cin >> fuel_capacity;
    cout << "How many miles can your car travel on a full tank of gas?" << endl;
    cin >> max_range;
    
    // calculate miles per gallon
    miles_per_gallon = max_range / fuel_capacity;
    
    // display mpg
    cout << "Your car's miles per gallon is " << miles_per_gallon << endl;
    
    // cin.get() added here on Mr. Noord's request.
    // cin.ignore() seems to be necessary to ignore the \n keyboard buffer.
    cin.ignore();
    cin.get();
    
    return 0;
}
