/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 5 Challenge 1
 *  Sum of Numbers: Write a program that asks the user for a positive integer 
 *  value. The program should use a loop to get the sum of all the integers
 *  from 1 up to the number entered. For example, if the user enters 50, the 
 *  loop will find the sum of 1, 2, 3, 4,..., 50.
 *  
 *  Invalid Input: Do no accept a negative starting number.
 */

# include <iostream>
using namespace std;

int main() 
{
    // Define variables
    int input_number, running_total;
    
    cout << "This program will calculate the sum of a series of numbers." << endl;
    cout << "Note: fails to correctly calculate very large numbers due to rollover.\n" << endl;
    
    // Prompt user for a positive number
    cout << "Enter a positive integer:" << endl;
    cin >> input_number;
    
    // Check if number is non-positive
    while (input_number <= 0)
    {
        cout << "\nERROR: Enter a positive integer" << endl;
        cin >> input_number;
    }
    
    // Loop through each number from one to the input number
    running_total = 0;
    for (int i = 1; i <= input_number; i++)
    {
        // with each loop advance the running total
        running_total += i;
    }
    
    // Display the resulting sum
    cout << "\nThe sum of all number from 1 to " << input_number << " is ";
    cout << running_total << "." << endl;
    
    cin.ignore();
    cin.get();
    return 0;
}

