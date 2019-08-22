/*  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 2 Challenge 10
 *  Mile per Gallon: A car hold 15 gallons of gasoline and can travel 375 miles 
 *  before refueling. Write a program that calculates the number of miles per 
 *  gallon the car gets. Display the result on the screen.
 * 
 *  MPG = Miles Driven / Gallons of Gas Used
 */

# include <iostream>
using namespace std;

int main() {
    /*  Constants for car gas tank capacity (gallons) and max miles before refueling
     *  Note: values stored as double to prevent flooring from integer division
    */  
    const double GAS_TANK_CAPACITY = 15;
    const double MAX_RANGE = 375;
    
    // Variable to store the calculated MPG
    double miles_per_gallon = MAX_RANGE / GAS_TANK_CAPACITY;
    
    cout << "This car's MPG rate is " << miles_per_gallon << endl;
    
    cin.get();
    return 0;
}