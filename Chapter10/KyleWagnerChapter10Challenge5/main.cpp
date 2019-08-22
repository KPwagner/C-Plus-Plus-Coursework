/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 10 Challenge 5
 *  Sentence Capitalizer: Write a function that accepts a pointer to a C-string 
 *  as an argument and capitalizes the first character of each sentence in the 
 *  string. For instance, if the string argument is 
 *  "hello. my name is Joe. what is your name?" 
 * 
 *  the function should manipulate the string so that it contains 
 *  "Hello. My name is Joe. What is your name?"
 * 
 *  Demonstrate the function in a program that asks the user to input a string 
 *  then passes it to the function. The modified string should be displayed on 
 *  the screen.
 * 
 *  Optional Exercise: Write an overloaded version of this function that accepts 
 *  a string class object as its argument.
 */

# include <iostream>
# include <cctype>
using namespace std;

void capitalizeString(char *);   // Function prototype

int main()
{
    const int SIZE = 300;
    char userString[SIZE];
    
    // Welcome message
    cout << "This program capitalizes the first word of each sentence in a string." << endl;
    
    // Prompt user for string input
    cout << "Enter a string with less that 300 characters:" << endl;
    cin.getline(userString, SIZE);
    
    // Call function to count string length and display results
    capitalizeString(userString);
    cout << "\nHere is your capitalized string:" << endl;
    cout << userString << endl;
    
    
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

void capitalizeString(char *strPtr)
{   
    // Capitalize the first character of the string
    *strPtr = toupper(*strPtr);
    
    // Step through string, capitalizing each character that follows a '.',
    // or follows a '.' and a space
    while (*strPtr != '\0')
    {
        if(*strPtr == '.')
        {
            if(*(strPtr + 1) == ' ')
                *(strPtr + 2) = toupper(*(strPtr + 2));
            else
                *(strPtr + 1) = toupper(*(strPtr + 1));
        }
        strPtr++;
    }
}

