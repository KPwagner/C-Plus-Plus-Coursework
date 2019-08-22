/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 7 Challenge 1
 *  Largest/Smallest Array Values: Write a program that lets the user enter ten 
 *  values into an array. The program should then display the largest and 
 *  smallest values stored in the array.
 *  
 */

# include <iostream>
using namespace std;

int main()
{
    // Declare constants and variables
    const int SIZE = 10;
    int numbers[SIZE];
    int count, highest, lowest;
    
    // Prompt user enter a value 10 times
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nEnter an integer value to add to the array at subscript " << i << endl;
        cin >> numbers[i];
        cin.ignore(20, '\n');   // Stops errors on floating point inputs
    }
    
    
    // Determine the highest value in the numbers array
    highest = numbers[0];
    for (count = 1; count < SIZE; count++)
    {
        if (numbers[count] > highest)
            highest = numbers[count];
    }
    
    // Determine the lowest value in the numbers array
    lowest = numbers[0];
    for (count = 1; count < SIZE; count++)
    {
        if (numbers[count] < lowest)
            lowest = numbers[count];
    }
    
    // Display the highest and lowest values
    cout << "\nThe highest value is " << highest << endl;
    cout << "The lowest value is " << lowest << endl;
    
    cin.get();
}