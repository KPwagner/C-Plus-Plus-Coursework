/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 3 Challenge 4
 *  Average Rainfall: Write a program that calculates the average rainfall for 
 *  three months. The program should ask the user to enter the name of each
 *  month, such as June or July, and the amount of rain (in inches) that fell 
 *  each month. The program should display a message similar to the following:
 *  
 *  The average rainfall for June, July, and August is 6.72 inches.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

int main () {
    // Initialize variables
    string month_1, month_2, month_3;
    double rainfall_1, rainfall_2, rainfall_3, three_month_average;
    
    // Request data from user
    cout << "This program calculates the average rainfall of three months." << endl;
    cout << "\nTo get started, enter the name of the first month you want to use for the average:" << endl;
    cin >> month_1;
    cout << "\nHow much rain (in inches) fell in " << month_1 << "?" << endl;
    cin >> rainfall_1;
    
    cout << "\nEnter the name of the second month you want to use for the average:" << endl;
    cin >> month_2;
    cout << "\nHow much rain (in inches) fell in " << month_2 << "?" << endl;
    cin >> rainfall_2;
    
    cout << "\nEnter the name of the third month you want to use for the average:" << endl;
    cin >> month_3;
    cout << "\nHow much rain (in inches) fell in " << month_3 << "?" << endl;
    cin >> rainfall_3;
    
    // Calculate the average
    three_month_average = (rainfall_1 + rainfall_2 + rainfall_3) / 3;
    
    // Display the data and average
    cout << "\nRAINFALL (in inches)" << endl;
    cout << "----------------------" << endl;
    cout << setprecision(2) << fixed;
    cout << left << setw(12) << month_1 << right << setw(6) << rainfall_1 << endl;
    cout << left << setw(12) << month_2 << right << setw(6) << rainfall_2 << endl;
    cout << left << setw(12) << month_3 << right << setw(6) << rainfall_3 << endl;
    cout << left << setw(12) << "Average" << right << setw(6) << three_month_average << endl;
    cout << "\nThe average rainfall for " << month_1 << ", " << month_2 << ", and ";
    cout << month_3 << " was " << three_month_average << " inches." << endl;
    
    // cin.get() added here on Mr. Noord's request.
    // cin.ignore() seems to be necessary to ignore the \n keyboard buffer.
    cin.ignore();
    cin.get();
    return 0;
}
