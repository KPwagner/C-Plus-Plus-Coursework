/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 10 Challenge 7
 *  Name Arranger: Write a program that asks for the user's first, middle, and 
 *  last names. The names should be stored in three different character arrays. 
 *  The program should then store, in a fourth array, the name arranged in the 
 *  following manner: the last name followed by a comma and a space, followed by 
 *  the first name and a space, followed by the middle name. For example, if the 
 *  user entered "Carol Lynn Smith", it should store "Smith, Carol Lynn" in the 
 *  fourth array. Display the contents of the fourth array on the screen.
 */

# include <iostream>
using namespace std;

// function prototypes
void splitNames(char *, char *, char *, char *);
void formatName(char *, char *, char *, char *);

int main()
{
    const int SIZE = 100;
    char userString[SIZE];
    char firstName[SIZE];
    char middleName[SIZE];
    char lastName[SIZE];
    char formattedName[SIZE];
    
    // Welcome message
    cout << "This program accepts the first, middle, and last name from a user" << endl;
    cout << "and outputs those names in a different format." << endl;
    
    // Prompt user for string input
    cout << "Enter your first, middle, and last name, separated by space." << endl;
    cin.getline(userString, SIZE);

    // Call function to split user input into separate name arrays
    splitNames(userString, firstName, middleName, lastName);
    cout << "\nFirst name: " << firstName << endl;
    cout << "Middle name: " << middleName << endl;
    cout << "Last name: " << lastName << endl;
    
    // Call function to format the names
    formatName(formattedName, firstName, middleName, lastName);
    cout << "Formatted name: " << formattedName << endl;
    
    cout << "\nPress [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

void splitNames(char *userPtr, char *firstPtr, char *middlePtr, char *lastPtr)
{       
    int name = 1;   // indicates first, middle, or last name
    
    // Step through string, assigning characters as needed
    while (*userPtr != '\0')
    {
        if(*userPtr == ' ')
        {
            name++;
        }
        else
        {
            switch(name)
            {
                case 1:
                    *firstPtr = *userPtr;
                    firstPtr++;
                    break;
                    
                case 2:
                    *middlePtr = *userPtr;
                    middlePtr++;
                    break;
                
                case 3:
                    *lastPtr = *userPtr;
                    lastPtr++;
                    break;
            }
        }
        userPtr++;
    }
}

void formatName(char *formattedPtr, char *firstPtr, char *middlePtr, char *lastPtr)
{
    // Step through last name and add each character to formatted name
    while(*lastPtr != '\0')
    {
        *formattedPtr = *lastPtr;
        lastPtr++;
        formattedPtr++;
    }
    
    // Add comma and space
    *formattedPtr = ',';
    formattedPtr++;
    *formattedPtr = ' ';
    formattedPtr++;
    
    // Step through first name and add each character to formatted name
    while(*firstPtr != '\0')
    {
        *formattedPtr = *firstPtr;
        firstPtr++;
        formattedPtr++;
    }
    *formattedPtr = ' ';
    formattedPtr++;
    
    // Step through middle name and add each character to formatted name
    while(*middlePtr != '\0')
    {
        *formattedPtr = *middlePtr;
        middlePtr++;
        formattedPtr++;
    }
}



