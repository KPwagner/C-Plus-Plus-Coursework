/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 8 Challenge 1
 *  Charge Account Validation: Write a program that lets the user enter a charge 
 *  account number. The program should determine if the number is valid by 
 *  checking for it in the following list:
 * 
 *  5658845 4520125 7895122 8777541 8451277 1302850
 *  8080152 4562555 5552012 5050552 7825877 1250255
 *  1005231 6545231 3852085 7576651 7881200 4581002
 *  
 *  The list of numbers above should be initialized in a single-dimensional 
 *  array. A simple linear search should be used to locate the number entered by 
 *  the user. If the user enters a number that is in the array, the program 
 *  should display a message saying the number is valid. If the user enters a 
 *  number that is not in the array, the program should display a message 
 *  indicating the number is invalid.
 */

# include <iostream>
# include <iomanip>
using namespace std;

// Function prototypes
bool isValid(const int[], int, int);
void testNumber(const int[], int, int);
void showNumbers(const int[], int, int);

int main()
{
    // Variables
    const int SIZE = 18;
    int user_number;
    int account_numbers[SIZE] = {
        5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
        1005231, 6545231, 3852085, 7576651, 7881200, 4581002
    };
    
    // Welcome message
    cout << "This program tests an account number against an array of numbers." << endl;
    cout << "Here is the array of numbers:" << endl;
    showNumbers(account_numbers, SIZE, 6);
    
    // User prompt
    cout << "Enter an account number to search for it in the array of numbers:" << endl;
    cin >> user_number;
    cin.ignore(20, '\n'); // Prevents problems on non-int user input
    
    testNumber(account_numbers, SIZE, user_number);
    
    cout << "Press [ENTER] to exit program" << endl;
    cin.get();
    return 0;
}

bool isValid(const int numbers[], int size, int user_number)
{
    int index = 0; // Used as subscript to search the array
    
    // Linear search returns true if the number is found
    while (index < size)
    {
        if(numbers[index] == user_number)
        {
            return true; // user_number was found
        }
        index++;
    }
    return false;   // user_number was not found
}

void testNumber(const int numbers[], int size, int user_number)
{
    cout << endl;
    cout << "Searching for " << user_number << ".........." << endl;
    if (isValid(numbers, size, user_number))
    {
        cout << "Account number " << user_number << " is VALID" << endl;
    }
    else
    {
        cout << "Account number " << user_number << " is INVALID" << endl;
    }
    cout << endl;
}

void showNumbers(const int numbers[], int size, int cols)
{
    cout << endl;
    for (int num = 1; num <= size; num++)
    {
        cout << setw(9) << right << numbers[num - 1];
        if (num % cols == 0)
            cout << endl;
    }
    cout << endl;
}

