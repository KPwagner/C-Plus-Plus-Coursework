/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 5 Challenge 4
 *  Calories Burned: Running on a particular treadmill you burn 3.6 calories 
 *  per minute. Write a program that uses a loop to display the number of 
 *  calories burned after 5, 10, 15, 20, 25, and 30 minutes.
 */

# include <iostream>
using namespace std;

int main() 
{
    // Constant for calories burned per minute
    const double CALORIES_PER_MINUTE = 3.6;
    
    // Variable for total calories burned
    double total_calories;
    
    // Loop through values from 5 to 30, in 5 minute increments
    for (int minutes = 5; minutes <= 30; minutes += 5)
    {
        double total_calories = minutes * CALORIES_PER_MINUTE;
        
        // Display the total calories burned for each length of time
        cout << "The total number of calories burned in " << minutes;
        cout << " minutes is " << total_calories << "." << endl; 
    }        
    
    cin.ignore();
    cin.get();
    return 0;
}
