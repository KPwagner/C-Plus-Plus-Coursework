/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 14 Challenge 7
 *  Month Class: Design a class named Month. The class should have the following 
 *  private members:
 *      name            a string object that holds the name of a month, such as 
 *                      "January", "February", and so on.
 *      monthNumber     an integer variable that holds the number of the month. 
 *                      For example, January would be 1, February would be 2, 
 *                      and so on. Valid values for this variable are 1 through 
 *                      12.
 * 
 *  In addition, provide the following member functions:
 *      *   A default constructor that sets monthNumber to 1 and name to 
 *          "January".
 *      *   A constructor that accepts the name of the month as an argument. It 
 *          should set name to the value passed as the argument and set 
 *          monthNumber to the correct value.
 *      *   A constructor that accepts the number of the month as an argument. 
 *          It should set monthNumber to the value passed as the argument and 
 *          set name to the correct month name.
 *      *   Appropriate set and get functions for the name and monthNumber 
 *          member variables.
 *      *   Prefix and postfix overloaded ++ operator functions that increment 
 *          monthNumber and set name to the name for next month. If monthNumber 
 *          is set to 12 when these functions execute, they should set 
 *          monthNumber to 1 and name to "January".
 *      *   Prefix and postfix overloaded -- operator functions that decrement 
 *          monthNumber and set name to the name of previous month. If 
 *          monthNumber is set to 1 when these functions execute, they should 
 *          set monthNumber to 12 and name to "December".
 * 
 *  Also, you should overload cout's << operator and cin's >> operator to work 
 *  with the Month class. Demonstrate the class in a program.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

class Month;        // forward declaration

// function prototypes for overloaded stream operators
ostream &operator << (ostream &, const Month &);
istream &operator >> (istream &, Month &);

class Month
{
    private:
        string name;
        int monthNumber;
    public:
        // default constructor
        Month()
        {
            name = "January";
            monthNumber = 1;
        }
        
        // constructor for string value initialization
        Month(string m)
        {
            name = m;
            setMonthNumber(m);
        }
        
        // constructor for int value initialization
        Month(int m)
        {
            monthNumber = m;
            setName(m);
        }
        
        // mutator member functions
        void setName(string m)
        {
            name = m;
        }
        
        void setName(int m)
        {
            switch(m)
            {
                case 1:
                    name = "January";
                    break;
                case 2:
                    name = "February";
                    break;
                case 3:
                    name = "March";
                    break;
                case 4:
                    name = "April";
                    break;
                case 5:
                    name = "May";
                    break;
                case 6:
                    name = "June";
                    break;
                case 7:
                    name = "July";
                    break;
                case 8:
                    name = "August";
                    break;
                case 9:
                    name = "September";
                    break;
                case 10:
                    name = "October";
                    break;
                case 11:
                    name = "November";
                    break;
                case 12:
                    name = "December";
                    break;
                default:
                    name = "";
                    cout << "*** there was a problem trying to set the month name ***" << endl;
                    cout << "Exiting program........................................" << endl;
                    exit(0);
            }
        }
        
        void setMonthNumber(int m)
        {
            monthNumber = m;
        }
        
        void setMonthNumber(string m)
        {
            if(m == "January")
                monthNumber = 1;
            else if (m == "February")
                monthNumber = 2;
            else if (m == "March")
                monthNumber = 3;
            else if (m == "April")
                monthNumber = 4;
            else if (m == "May")
                monthNumber = 5;
            else if (m == "June")
                monthNumber = 6;
            else if (m == "July")
                monthNumber = 7;
            else if (m == "August")
                monthNumber = 8;
            else if (m == "September")
                monthNumber = 9;
            else if (m == "October")
                monthNumber = 10;
            else if (m == "November")
                monthNumber = 11;
            else if (m == "December")
                monthNumber = 12;
            else
            {
                name = "";
                cout << "*** there was a problem trying to set the month number ***" << endl;
                cout << "Exiting program........................................" << endl;
                exit(0);
            }
        }
        
        // accessor member functions
        string getName()
        {
            return name;
        }
        
        int getMonthNumber()
        {
            return monthNumber;
        }
        
        // operator overloading
        Month operator++();
        Month operator++(int);
        Month operator--();
        Month operator--(int);
        
        // friends
        friend ostream &operator << (ostream &, const Month &);
        friend istream &operator >> (istream &, Month &);
};        

// prefix increment operator overloading
Month Month::operator++()
{
    ++monthNumber;
    if (monthNumber == 13)
        monthNumber = 1;
    setName(monthNumber);
    return *this;
}

// postfix increment operator overloading
Month Month::operator++(int)
{
    monthNumber++;
    if (monthNumber == 13)
        monthNumber = 1;
    setName(monthNumber);
    return *this;
}

// prefix decrement operator overloading
Month Month::operator--()
{
    --monthNumber;
    if (monthNumber == 0)
        monthNumber = 12;
    setName(monthNumber);
    return *this;
}

// postfix decrement operator overloading
Month Month::operator--(int)
{
    monthNumber--;
    if (monthNumber == 0)
        monthNumber = 12;
    setName(monthNumber);
    return *this;
}

// << operator overloading
ostream &operator << (ostream &strm, const Month &obj)
{
    strm << '(' << obj.monthNumber << ") " << obj.name;
    return strm;
}

// >> operator overloading
istream &operator >> (istream &strm, Month &obj)
{
    cout << "Enter number of month: ";
    strm >> obj.monthNumber;
    obj.setName(obj.monthNumber);    
    cin.clear();
    cin.ignore(256, '\n');
    return strm;
}

int main()
{   
    // welcome message
    cout << "This program uses a class named Month to create objects that store the names " << endl;
    cout << "and number values of months." << endl;
    cout << endl;
    
    // begin demonstration
    cout << "To demonstrate, here a Month object named 'testMonth' is initialized using " << endl;
    cout << "the default constructor." << endl;
    Month testMonth;
    cout << endl;
    cout << "Here are the member variables of testMonth (using accessor member functions):" << endl;
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    cout << testMonth.getMonthNumber() << "\t\t" << testMonth.getName() << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "Another Month object named testMonthTwo is initialized with int value 6." << endl;
    Month testMonthTwo(6);
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    cout << testMonthTwo.getMonthNumber() << "\t\t" << testMonthTwo.getName() << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "Another Month object named testMonthThree is initialized with string value 'October'." << endl;
    Month testMonthThree("October");
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    cout << testMonthThree.getMonthNumber() << "\t\t" << testMonthThree.getName() << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "Changing testMonth with mutator function, passing int value 11." << endl;
    cout << "Note: name value does not automatically update." << endl;
    testMonth.setMonthNumber(11);
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    cout << testMonth.getMonthNumber() << "\t\t" << testMonth.getName() << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "Updating member variable name of testMonth to 'November' with mutator function." << endl;
    testMonth.setName("November");
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    cout << testMonth.getMonthNumber() << "\t\t" << testMonth.getName() << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "The Month class has overloaded increment (++) and decrement (--) operators, both prefix and postfix." << endl;
    cout << "Incrementing testMonth three times...................." << endl;
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        testMonth++;
        cout << testMonth.getMonthNumber() << "\t\t" << testMonth.getName() << endl;
    }
    cout << endl;
    cout << "Notice how the name and monthNumber wrap around from December to January (12 to 1)." << endl;
    
    cout << "Decrementing testMonth five times...................." << endl;
    cout << endl;
    cout << "monthNumber\tname" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        testMonth--;
        cout << testMonth.getMonthNumber() << "\t\t" << testMonth.getName() << endl;
    }
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "The Month class also has overloaded >> and << operators." << endl;
    cout << endl;
    cout << "Here is the result of 'cout << testMonth':" << endl;
    cout << testMonth;
    cout << "\n\n";
    cout << "Here is the result of 'cin >> testMonth' followed by 'cout << testMonth':" << endl;
    cin >> testMonth;
    cout << testMonth;
            
    
    // exit message
    cout << "\n\n";
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

