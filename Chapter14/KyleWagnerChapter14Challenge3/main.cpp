 /*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 14 Challenge 3
 *  Day of the Year Modification: Modify the DayOfYear class (challenge 2, see 
 *  below) to add a constructor that takes two parameters: a string object 
 *  representing a month and an integer in the range 0 through 31 representing 
 *  the day of the month. The constructor should then initialize the integer 
 *  member of the class to represent the day specified by the month and day of 
 *  month parameters. The constructor should terminate the program with an 
 *  appropriate error message if the number entered for a day is outside the 
 *  range of days for the month given.
 * 
 *  Day of Year: Assuming a year has 365 days, write a class named DayOfYear 
 *  that takes an integer representing a day of the year and translates it to a 
 *  string consisting of the month followed by day of the month. For example,
 *      Day 2 would be January 2.
 *      Day 32 would be February 1.
 *      Day 365 would be December 31.
 *  
 *  The constructor for the class should take as parameter an integer 
 *  representing the day of the year, and the class should have a member 
 *  function print() that prints the day in the month-day format. The class 
 *  should have an integer member variable to represent the day, and should have 
 *  static member variables holding string objects that can be used to assist in 
 *  the translation from the integer format to the month-day format.
 * 
 *  Test your class by inputting various integers representing days and printing 
 *  out their representation in the month-day format.
 *  
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

class DayOfYear
{
private:
    int dayOfYear;
    static int monthDays[12];
    static string months[12];
    
public:
    DayOfYear(int n)
    {
        dayOfYear = n;
    }
    
    DayOfYear(string s, int d)
    {   
        int totalDays = 0;      // tracks days of year
        bool isMonth = false;        // used for conditional check
        bool isDayOfMonth = false;   // used for conditional check
        
        // loops through each month of the year
        for (int m = 0; m < 12 ; m++)
        {
            // if user's string input matches a string month in the months array
            if (s == months[m])
            {
                // set conditional check for month to true
                isMonth = true;
                // if day of month is in the correct range, set conditional 
                // check for day of month to true
                if (d > 0 && d <= monthDays[m])
                    isDayOfMonth = true;
                
                totalDays += d;
                dayOfYear = totalDays;
                break;
            }
            else
            {
                totalDays += monthDays[m];
            }
        }
        
        if (!isMonth)
        {
            cout << "*** the month you entered does not exist ***" << endl;
            cout << "*** check spelling, and make sure to capitalize the first letter ***" << endl;
            cout << "Exiting Program...................................................." << endl;
            exit(0);
        }
        if (!isDayOfMonth)
        {
            cout << "*** the day of month you entered is outside of the valid range ***" << endl;
            cout << "Exiting Program...................................................." << endl;
            exit(0);
        }
    }
    
    void print() const
    {
        // declare variables
        int month;
        int dayOfMonth;
        
        cout << "Day of year is " << dayOfYear << endl;
        cout << "Word representation is ";
        
        // initialize dayOfMonth to the value of user input
        // dayOfMonth will be modified in the loop below
        dayOfMonth = dayOfYear;
        
        // loop through the monthDay array to find the correct month and day of month
        for (int m = 0; m < 12; m++)
        {
            if (dayOfMonth - monthDays[m] <= 0)
            {
                month = m;
                cout << months[month] << ' ' << dayOfMonth << endl;
                break;
            }
            dayOfMonth -= monthDays[m];         
        }
    }
};

// array with the number of days in each of the 12 months as integers
int DayOfYear::monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

// array with names of the 12 months as strings
string DayOfYear::months[12] = {"January", "February", "March", "April", "May", 
                            "June", "July", "August", "September", "October", 
                            "November", "December"};

int main()
{
    int userDay;
    string userMonth;
    int userDayOfMonth;
    
    // welcome message
    cout << "This program uses a class named DayOfYear to display a word format representation ";
    cout << "of a day of the year. For example," << endl;
    cout << "\tDay 2 would be January 2." << endl;
    cout << "\tDay 32 would be February 1." << endl;
    cout << "\tDay 365 would be December 31." << endl;
    cout << endl;
    
    // prompts user for input
    cout << "Enter a day number in the range 1-365:  ";
    do
    {
        cin >> userDay;
        // cin.clear and cin.ignore eliminate some errors with user input
        cin.clear();
        cin.ignore(365, '\n');
        
        if (userDay < 1 || userDay > 365)
            cout << "*** enter a day in the range 1-365 ***" << endl;
    } while (userDay < 1 || userDay > 365);
    
    // creates DayOfYear object and calls print function
    DayOfYear dayOne(userDay);
    dayOne.print();
    
    cout << "\n\n";
    
    // prompts user to enter a month and day of month
    cout << "Enter a month (as a word, capitalized) and a day of month, separated by a space:  ";
    cin >> userMonth >> userDayOfMonth;
    // cin.clear and cin.ignore eliminate some errors with user input
    cin.clear();
    cin.ignore(256,'\n');
    
    // creates DayOfYear object and calls print function
    DayOfYear dayTwo(userMonth, userDayOfMonth);
    dayTwo.print();
    
    // exit message
    cout << "\n\n";
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}
