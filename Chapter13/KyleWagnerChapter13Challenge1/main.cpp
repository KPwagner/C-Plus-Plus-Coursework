/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 13 Challenge 1
 *  Date: Design a class called Date. The class should store a date in three 
 *  integers: month, day, and year. There should be member functions to print 
 *  the date in the following forms:
 *      12/25/2018
 *      December 25, 2018
 *      25 December 2018
 * 
 *  Demonstrate the class by writing a complete program implementing it.
 * 
 *  Input Validation: Do not accept values for the day greater than 31 or less 
 *  than 1. Do not accept values for the month greater than 12 or less than 1.
 */

# include <iostream>
# include <string>
using namespace std;

// Date class declaration
class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        string getStringMonth() const;
        void displayDateOne() const;
        void displayDateTwo() const;
        void displayDateThree() const;
};

void Date::setMonth(int m)
{
    month = m;
}

void Date::setDay(int d)
{
    day = d;
}

void Date:: setYear(int y)
{
    year = y;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

int Date::getYear() const
{
    return year;
}

string Date::getStringMonth() const
{
    switch(month)
    {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default:
            return "*** error ***";
            break;
    }
}

// displays date in the following format: 12/25/2018
void Date::displayDateOne() const
{
    cout << month << '/' << day << '/' << year << endl;
}

// displays date in the following format: December 25, 2018
void Date::displayDateTwo() const
{
    cout << getStringMonth() << ' ' << day << ", " << year << endl;
}

// displays date in the following format: 25 December 2018
void Date::displayDateThree() const
{
    cout << day << ' ' << getStringMonth() << ' ' << year << endl;
}

int main()
{
    // Welcome message
    cout << "This program uses a class named Date to store a date from a user." << endl;
    cout << endl;
    
    // defines instance of the date class
    Date date;
    
    // local variables
    int month;
    int day;
    int year;
   
    // gets month from user, accepting only values 1-12
    do
    {
        cout << "Enter the month of your date (as an number):  ";
        cin >> month;
        cin.ignore(256, '\n');  // cleans stream, reduces input errors
        if (month < 1 || month > 12)
        {
            cout << "*** enter month in the range of 1-12 ***" << endl;
        }
    } while(month < 1 || month > 12);
    cout << endl;
    date.setMonth(month);
    
    // gets day from user, accepting only values 1-31
    do
    {
        cout << "Enter the day of your date (as an monthly number):  ";
        cin >> day;
        cin.ignore(256, '\n');  // cleans stream, reduces input errors
        if (day < 1 || day > 31)
        {
            cout << "*** enter day in the range of 1-31 ***" << endl;
        }
    } while(day < 1 || day > 31);
    cout << endl;
    date.setDay(day);
    
    // gets year from user
    cout << "Enter the year of your date:  ";
    cin >> year;
    cin.ignore(256, '\n');
    date.setYear(year);
    cout << endl;
    
    // Display the results
    cout << "Here is your date displayed three different ways:" << endl;
    date.displayDateOne();
    date.displayDateTwo();
    date.displayDateThree();
    cout << endl;
    
    // Exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

