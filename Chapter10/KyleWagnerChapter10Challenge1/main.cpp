/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 10 Challenge 1
 *  String Length: Write a function that returns an integer and accepts a 
 *  pointer to a  C-string as an argument. The function should count the number 
 *  of characters in the string and return that number. Demonstrate the function 
 *  in a simple program that asks the user to input a string, passes it to the 
 *  function, then displays the function's return value.
 */

# include <iostream>
# include <cctype>
using namespace std;

int countCharacters(char *);   // Function prototype

int main()
{
    const int SIZE = 100;
    char userString[SIZE];
    int numCharacters;
    
    // Welcome message
    cout << "This program counts the number of characters in a string." << endl;
    
    // Prompt user for string input
    cout << "Enter a string with less that 100 characters:" << endl;
    cin.getline(userString, SIZE);
    
    // Call function to count string length and display results
    numCharacters = countCharacters(userString);
    cout << "\nThe string you entered is " << numCharacters << " characters long." << endl;
    
    cout << "\nPress [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

int countCharacters(char *strPtr)
{
    int count = 0;  // length of string
    
    // Step through string, counting its length
    while (*strPtr != '\0')
    {
        count++;
        strPtr++;
    }
    return count;
}