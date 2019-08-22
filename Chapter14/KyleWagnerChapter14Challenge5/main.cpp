/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 14 Challenge 5
 *  TimeOff: Design a class named TimeOff. The purpose of the class is to track 
 *  an employee's sick leave, vacation, and unpaid time off. It should have, as 
 *  members, the following instances of the NumDays class described in 
 *  Programming Challenge 4 (see below):
 *      maxSickDays     A NumDays object that records the maximum number of days 
 *                      of sick leave the employee may take.
 *      sickTaken       A NumDays object that records the number of days of sick 
 *                      leave the employee has already taken.
 *      maxVacation     A NumDays object that records the maximum number of days 
 *                      of paid vacation the employee may take.
 *      vacTaken        A NumDays object that records the number of days of paid 
 *                      vacation the employee has already taken.
 *      maxUnpaid       A NumDays object that records the maximum number of days 
 *                      of unpaid vacation the employee may take.
 *      unpaidTaken     A NumDays object that records the number of days of 
 *                      unpaid leave the employee has taken.
 * 
 *  Additionally, the class should have members for holding the employee's name 
 *  and identification number. It should have appropriate constructor and member 
 *  functions for storing and retrieving data in any of the member objects.
 * 
 *  Input Validation: Company policy states that an employee may not accumulate 
 *  more than 240 hours of paid vacation. The class should not allow the 
 *  maxVacation object to store a value greater than this amount.
 * 
 *  NumDays Class (Challenge 4): Design a class called NumDays. The class's 
 *  purpose is to store a value that represents a number of work hours and 
 *  convert it to a number of days. For example, 8 hours would be converted to 1 
 *  day, 12 hours would be converted to 1.5 days, and 18 hours would be 
 *  converted to 2.25 days. The class should have a constructor that accepts a 
 *  number of hours, as well as member functions for storing and retrieving the 
 *  hours and days. The class should also have the following overloaded 
 *  operators:
 *      +   Addition operator. When two NumDays objects are added together, the 
 *          overloaded + operator should return the sum of the two objects' 
 *          hours members.
 *      -   Subtraction operator. When one NumDays object is subtracted from 
 *          another, the overloaded - operator should return the difference of 
 *          the two objects' hours members.
 *      ++  Prefix and postfix increment operators. These operators should 
 *          increment the number of hours stored in the object. When 
 *          incremented, the number of days should be automatically 
 *          recalculated.
 *      --  Prefix and postfix decrement operators. These operators should 
 *          decrement the number of hours stored in the object. When 
 *          decremented, the number of days should be automatically 
 *          recalculated.
 *  
 */

# include <iostream>
# include <iomanip>
# include <string>
# include "NumDays.h"
# include "TimeOff.h"
using namespace std;

int main()
{   
    int count;
    
    // welcome message
    cout << "This program uses a class named NumDays to create objects with numbers " << endl;
    cout << "representing work days and work hours. A work day is defined as 8 work hours." << endl;
    cout << endl;
    
    cout << "To demonstrate this class, three objects are created (sally, bob, and debbie)." << endl;
    cout << "These objects utilize the constructor to initialize hours to 40, 50, and 55." << endl;
    NumDays sally(40);
    NumDays bob(50);
    NumDays debbie(55);
    
    cout << "Here is a table summarizing the objects by using the accessor member functions:" << endl;
    cout << endl;
    cout << "\t\tHours\t\tDays" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "sally\t\t" << sally.getWorkHours() << "\t\t" << sally.getWorkDays() << endl;
    cout << "bob\t\t" << bob.getWorkHours() << "\t\t" << bob.getWorkDays() << endl;
    cout << "debbie\t\t" << debbie.getWorkHours() << "\t\t" << debbie.getWorkDays() << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue......................................................." << endl;
    cin.get();
    cout << endl;
    
    cout << "NumDays has overloaded + and - operators." << endl;
    cout << "To demonstrate the overloaded operator functionality, three new objects are created:" << endl;
    cout << "\tweekOne with 50 work hours" << endl;
    cout << "\tweekTwo with 45 work hours" << endl;
    cout << "\tweekThree with 40 work hours" << endl;
    cout << endl;
    NumDays weekOne(50);
    NumDays weekTwo(45);
    NumDays weekThree(40);
    
    cout << "Using the overloaded + operator, the sum hours of weekOne and weekTwo is " << weekOne + weekTwo << endl;
    cout << "Using the overloaded - operator, the hours difference of weekOne and weekTwo is " << weekOne - weekTwo << endl;
    
    cout << "\n\n";
    cout << "Press [Enter] to continue......................................................." << endl;
    cin.get();
    cout << endl;
    
    NumDays first;
    NumDays second(50);
    cout << "NumDays has overloaded prefix and postfix ++ and -- operators too." << endl;
    cout << "Demonstrating prefix ++ operator." << endl;
    for (count = 0; count < 4; count++)
    {
        first = ++second;
        cout << "first: " << first.getWorkHours();
        cout << "\tsecond: " << second.getWorkHours();
        cout << endl;
    }
    
    cout << "\n\nDemonstrating postfix ++ operator." << endl;
    for (count = 0; count < 4; count++)
    {
        first = second++;
        cout << "first: " << first.getWorkHours();
        cout << "\tsecond: " << second.getWorkHours();
        cout << endl;
    }
    
    cout << "\n\nDemonstrating prefix -- operator." << endl;
    for (count = 0; count < 4; count++)
    {
        first = --second;
        cout << "first: " << first.getWorkHours();
        cout << "\tsecond: " << second.getWorkHours();
        cout << endl;
    }
    
    cout << "\n\nDemonstrating postfix -- operator." << endl;
    for (count = 0; count < 4; count++)
    {
        first = second--;
        cout << "first: " << first.getWorkHours();
        cout << "\tsecond: " << second.getWorkHours();
        cout << endl;
    }
    
    cout << "\n\n";
    cout << "Press [Enter] to continue......................................................." << endl;
    cin.get();
    cout << endl;
    
    cout << "A class named TimeOff is used to store the following information about an employee:" << endl;
    cout << "\tname\n\tID\n\tmax sick days\n\tsick days taken\n\tmax vacation";
    cout << "\n\tvacation taken\n\tmax unpaid vacation\n\tunpaid vacation taken" << endl;
    cout << endl;
    cout << "Here, a TimeOff object is created using the constructor passing the following arguments:" << endl;
    cout << "\tname: James Bond\n\tID: 7\n\tmax sick days: 125";
    cout << "\n\tsick days taken: 0\n\tmax vacation: 240\n\tvacation taken: 24";
    cout << "\n\tmax unpaid vacation: 87\n\tunpaid vacation taken: 5" << endl;
    cout << endl;
    cout << "Note: these quantities are stored in NumDays objects." <<endl;
    cout << endl;
    cout << "Then, the employee's information is displayed with the TimeOff member function 'print'." << endl;
    
    TimeOff jamesBond("James Bond", 7, 125, 0, 240, 24, 87, 5);
    jamesBond.print();
    
    cout << "\n\n";
    cout << "Press [Enter] to continue......................................................." << endl;
    cin.get();
    cout << endl;
    
    cout << "Here, another TimeOff object is created using the default constructor, passing no arguments." << endl;
    cout << "Then, the objects member variables are set using TimeOff member functions." << endl;
    cout << endl;
    TimeOff elonMusk;
    cout << setfill('.');
    cout << setw(90) << left << "Member function setting employee's name to 'Elon Musk'" << endl;
    elonMusk.setEmployeeName("Elon Musk");
    cout << setw(90) << left << "Member function setting employee's ID to 1" << endl;
    elonMusk.setEmployeeID(1);
    cout << setw(90) << left << "Member function setting employee's max sick days to 13" << endl;
    elonMusk.setMaxSickDays(13);
    cout << setw(90) << left << "Member function setting employee's sick days taken 7" << endl;
    elonMusk.setSickTaken(7);
    cout << setw(90) << left << "Member function setting employee's max vacation to 870" << endl;
    elonMusk.setMaxVacation(870);
    cout << setw(90) << left << "Member function setting employee's vacation taken to 3" << endl;
    elonMusk.setVacTaken(3);
    cout << setw(90) << left << "Member function setting employee's max unpaid vacation to 55" << endl;
    elonMusk.setMaxUnpaid(55);
    cout << setw(90) << left << "Member function setting employee's unpaid vacation taken to 0" << endl;
    elonMusk.setUnpaidTaken(0);
    cout << endl;
    cout << setfill(' ');
    
    cout << "Then, the employee's information is displayed with the TimeOff member function 'print'." << endl;
    elonMusk.print();
    cout << endl;
    cout << "NOTE: the value stored for max vacation was 30 (equivalent to 240 hours) because it is " << endl;
    cout << "the maximum allowed number of vacation days." << endl;
    
    // exit message
    cout << "\n\n";
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

