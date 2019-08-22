/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 14 Challenge 1
 *  Numbers Class: Design a class Numbers that can be used to translate whole 
 *  dollar amounts in the range 1 through 9999 into an English description of 
 *  the number. For example, the number 713 would be translated into the string 
 *  seven hundred thirteen, and 8203 would be translated into eight thousand two 
 *  hundred three. The class should have a single integer member variable:
 * 
 *  int number;
 * 
 *  and a static array of string objects that specify how to translate key dollar 
 *  amounts into the desired format. For example, you might use static strings 
 *  such as
 * 
 *  string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen");
 *  string hundred = "hundred";
 *  string thousand = "thousand";
 * 
 *  The class should have a constructor that accepts a non-negative integer and 
 *  uses it to initialize the Numbers object. It should have a member function 
 *  print() that prints the English descriptions of the Numbers object. 
 *  Demonstrate the class by writing a main program that asks the user to enter 
 *  a number in the proper range then prints out its English description.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// Numbers class
class Numbers
{
    private:
        // single member variable
        int number;
        
        // static string arrays to hold number words
        static string lessThan20[20];
        static string ten[10];
        static string hundred;
        static string thousand;
        
    public:
        Numbers(int n)
        {
            number = n;
        }
        
        void print() const
        {
            // variable declarations to track pieces of number
            // tempNumber keeps track of remaining pieces of number as it is
            // broken up
            int tempNumber;
            int thousands;
            int hundreds;
            int tens;
            int ones;
            
            // calculates thousands place and updates tempNumber with remainder
            thousands = number / 1000;
            tempNumber = number % 1000;
            
            // displays thousands, if any
            if (thousands > 0)
            {
                cout << lessThan20[thousands] << " "<< thousand;
            }
            
            // calculates hundreds place and updates tempNumber with remainder
            hundreds = tempNumber / 100;
            tempNumber = tempNumber % 100;
            
            // displays hundreds, if any
            if (hundreds > 0)
            {
                // if statement adds space if thousands were displayed
                if (thousands)
                    cout << ' ';
                cout << lessThan20[hundreds] << " " << hundred;
            }
            
            // calculates tens place and updates tempNumber with remainder
            tens = tempNumber / 10;
            
            // displays tens place as 'twenty', 'thirty', etc.
            // if else handles teen numbers when tens less than 2 ('twenty')
            if (tens > 1)
            {
                if (hundreds)
                    cout << ' ';
                cout << ten[tens];
                tempNumber = tempNumber % 10;
                if (tempNumber > 0)
                    cout << ' ' << lessThan20[tempNumber];
            }
            else
            {
                if (hundreds && tempNumber)
                    cout << ' ';
                if (tempNumber > 0)
                    cout << lessThan20[tempNumber];
            }
        }
};


// definitions of the static member variables
string Numbers::lessThan20[20] = {  "zero", "one", "two", "three", "four", "five",
                                    "six", "seven", "eight", "nine", "ten", "eleven",
                                    "twelve", "thirteen", "fourteen", "fifteen",
                                    "sixteen", "seventeen", "eighteen", "nineteen"};

string Numbers::ten[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty",
                            "seventy", "eighty", "ninety"};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";



int main()
{
    int userNumber;
    
    // welcome message
    cout << "This program uses a class named Numbers to convert an int number value in the " << endl;
    cout << "range 1-9999 to an English description of the number." << endl;
    cout << endl;
    cout << "To demonstrate this functionality, you will be prompted to enter a number." << endl;
    cout << "\n\n\n";
    
    // prompts user to enter a number
    cout << "Enter an integer in the range 1-9999." << endl;
    
    // loop to collect user input and check that is is valid (range of 1-9999)
    do
    {
        cin >> userNumber;
        cin.ignore(256,'\n');   // cleans stream, preventing some compiler problems
        if (userNumber < 1 || userNumber > 9999)
        {
            cout << "*** number must be in the range 1-9999" << endl;
        }
    } while (userNumber < 1 || userNumber > 9999);
    
    // creates Number object from user input
    Numbers num(userNumber);
    
    // displays number in word form by calling the class member function print
    cout << endl;
    cout << "Your number in word form is '";
    num.print();
    cout << "'.";
    
    // exit message
    cout << "\n\n";
    cout << "Press [Enter] to exit this program." << endl;
    cin.get();
    return 0;
}

