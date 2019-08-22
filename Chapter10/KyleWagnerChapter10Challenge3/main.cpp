/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 10 Challenge 3
 *  Word Counter: Write a function that accepts a pointer to a C-string as an 
 *  argument and returns the number of words contained in the string. For 
 *  instance, if the string argument is "Four score and seven years ago" the 
 *  function should return the number 6. Demonstrate the function in a program 
 *  that asks the user to input a string then passes it to the function. The 
 *  number of words in the string should be displayed on the screen. 
 * 
 *  Optional Exercise: Write an overloaded version of this function that accepts 
 *  a string class object as its argument.
 */

# include <iostream>
using namespace std;

int countWords(char *);   // Function prototype

int main()
{
    const int SIZE = 100;
    char userString[SIZE];
    int numWords;
    
    // Welcome message
    cout << "This program counts the number of words in a string." << endl;
    
    // Prompt user for string input
    cout << "Enter a string with less that 100 characters:" << endl;
    cin.getline(userString, SIZE);
    
    // Call function to count string length and display results
    numWords = countWords(userString);
    cout << "\nWord count: " << numWords << endl;
    
    cout << "\nPress [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

int countWords(char *strPtr)
{
    int count = 0;  // number of words
    
    // Sets starting count to 1 if the string does not start with a space
    if(*strPtr != ' ')
        count = 1;
    
    // Step through string, counting words
    while (*strPtr != '\0')
    {
        if(*strPtr == ' ')
        {
            if (*(strPtr + 1) != ' ' && *(strPtr + 1) != '\0')
                count++;
        }
        strPtr++;
    }
    return count;
}

