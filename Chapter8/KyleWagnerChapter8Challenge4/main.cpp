/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 8 Challenge 4
 *  Charge Account Validation Modification: Modify the program you wrote for
 *  Programming Challenge 2 (Lottery Winners, shown below) so it performs a 
 *  binary search instead of a linear search.
 * 
 *  Lottery Winners: A lottery ticket buyer purchases ten tickets a week, always 
 *  playing the same ten 5-digit "lucky" combinations. Write a program that 
 *  initializes an array or a vector with these numbers, then lets the player 
 *  enter this week's winning 5-digit number. The program should perform a 
 *  linear search through the list of the player's numbers and report whether or 
 *  not one of the tickets is a winner this week. Here are the numbers:
 *  13579   26791   26792   33445   55555
 *  62483   77777   79422   85647   93121
 * 
 */

# include <iostream>
# include <iomanip>
using namespace std;

// Function prototypes
void showNumbers(const int[], int, int);
void testNumber(const int[], int, int);
bool isWinner(const int[], int, int);

int main()
{
    // Variables
    const int SIZE = 10;
    int winning_number;
    
    // These numbers must be sorted in order because a binary search is used
    int lucky_numbers[SIZE] = {
        13579, 26791, 26792, 33445, 55555,
        62483, 77777, 79422, 85647, 93121
    };
    
    // Welcome message
    cout << "This program tests the winning lottery number against a set of " << endl;
    cout << "purchased \"lucky\" numbers." << endl; 
    cout << "Here is the array of lucky numbers:" << endl;
    showNumbers(lucky_numbers, SIZE, 5);
    
    // User prompt
    cout << "Enter the winning lottery number:" << endl;
    cin >> winning_number;
    cin.ignore(20, '\n'); // Prevents problems on non-int user input
    
    testNumber(lucky_numbers, SIZE, winning_number);
    
    cout << "Press [ENTER] to exit program" << endl;
    cin.get();
    return 0;
}

bool isWinner(const int numbers[], int size, int winning_number)
{   
    // Variables
    int first = 0,
        last = size -1,
        middle;
      
    // Binary search returns true if winning number is found
    while (first <= last)
    {
        middle = (first + last) / 2;
        if (numbers[middle] == winning_number)
        {
            return true; // Winning number found
        }
        else if (numbers[middle] > winning_number)
            last = middle -1;
        else
            first = middle + 1;
    }
    return false; // Winning number not found
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

void testNumber(const int numbers[], int size, int winning_number)
{
    cout << endl;
    cout << "Searching for " << winning_number << ".........." << endl;
    if (isWinner(numbers, size, winning_number))
    {
        cout << "You won because you player number " << winning_number << "!" << endl;
    }
    else
    {
        cout << "Looks like you did not win this time." << endl;
    }
    cout << endl;
}
