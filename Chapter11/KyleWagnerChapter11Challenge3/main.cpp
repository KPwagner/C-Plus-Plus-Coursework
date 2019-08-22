/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 11 Challenge 3
 *  Corporate Sales Data: Write a program that uses a structure to store the 
 *  following data on a company division:
 *      Division Name (such as East, West, North, or South)
 *      First-Quarter Sales
 *      Second-Quarter Sales
 *      Third-Quarter Sales
 *      Fourth-Quarter Sales
 *      Total Annual Sales
 *      Average Quarterly Sales
 * 
 *  The program should use four variables of this structure. Each variable 
 *  should represent one of the following corporate divisions: East, West, 
 *  North, and South. The user should be asked for the four quarters' sales 
 *  figures for each division. Each division's total and average sales should be 
 *  calculated and stored in the appropriate member of each structure variable. 
 *  These figures should then be displayed on the screen.
 * 
 *  Input Validation: Do no accept negative numbers for any sales figures.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// User-defined types
struct DivisionData
{
    string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function prototypes
void getDivisionData(DivisionData&);
void showDivisionData(DivisionData);
void showAllData(DivisionData, DivisionData, DivisionData, DivisionData);

int main()
{
    // Welcome message
    cout << "This program will ask you for sales figures of four company divisions." << endl;
    cout << "Those sales figures will be calculated into totals and averages, then displayed." << endl;
    
    // DivisionData variables, initialized with test data
    DivisionData east = {"East", 455.55, 546.45, 654.54, 754.34, 1600.00, 400.00};
    DivisionData west = {"West", 234.34, 345.35, 378.43, 455.54, 1800.00, 450.00};
    DivisionData north = {"North", 677.77, 687.56, 789.56, 877.67, 2000.00, 500.00};
    DivisionData south = {"South", 122.23, 134.34, 245.23, 345.44, 2200.00, 550.00};
    
    cout << "\nEnter the quarterly sales data for the East division." << endl;
    getDivisionData(east);
    cout << "\nEnter the quarterly sales data for the West division." << endl;
    getDivisionData(west);
    cout << "\nEnter the quarterly sales data for the North division." << endl;
    getDivisionData(north);
    cout << "\nEnter the quarterly sales data for the South division." << endl;
    getDivisionData(south);    
    
    showAllData(east, west, north, south);
    
    // Exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();            
}


// getDivisionData function collects quarterly sales data from user, 
// assigning it to the DivisionData structure argument
void getDivisionData(DivisionData &division)
{
    // Variable declarations; q1,q2,q3, and q4 inititalized to -1 for input validation loop
    double q1 = -1;
    double q2 = -1;
    double q3 = -1;
    double q4 = -1;
    double total, average;
    
    // Prompts user for first quarter sales
    cout << "First Quarter Sales:" << endl;
    while(q1 < 0)
    {
        cin >> q1;
        cin.ignore(20, '\n');   // Prevents malfunction from some bad user input
        if (q1 < 0)
            cout << "*** Enter a non-negative value ***" << endl;
    }
    
    // Prompts user for second quarter sales
    cout << "Second Quarter Sales:" << endl;
    while(q2 < 0)
    {
        cin >> q2;
        cin.ignore(20, '\n');   // Prevents malfunction from some bad user input
        if (q2 < 0)
            cout << "*** Enter a non-negative value ***" << endl;
    }
    
    // Prompts user for third quarter sales
    cout << "Third Quarter Sales:" << endl;
    while(q3 < 0)
    {
        cin >> q3;
        cin.ignore(20, '\n');   // Prevents malfunction from some bad user input
        if (q3 < 0)
            cout << "*** Enter a non-negative value ***" << endl;
    }
    
    // Prompts user for fourth quarter sales
    cout << "Fourth Quarter Sales:" << endl;
    while(q4 < 0)
    {
        cin >> q4;
        cin.ignore(20, '\n');   // Prevents malfunction from some bad user input
        if (q4 < 0)
            cout << "*** Enter a non-negative value ***" << endl;
    }
    
    total = q1 + q2 + q3 + q4;      // Calculates total annual sales
    average = total / 4;            // Calculates quarterly average sales
    
    division.firstQuarterSales = q1;
    division.secondQuarterSales = q2;
    division.thirdQuarterSales = q3;
    division.fourthQuarterSales = q4;
    division.totalAnnualSales = total;
    division.averageQuarterlySales = average;
}


// showDivisionData function displays the sales data of the DivisionData structure argument
void showDivisionData(DivisionData division)
{
    cout << setprecision(2) << fixed;
    cout << setw(25) << left << "First Quarter" << setw(10) << right << division.firstQuarterSales << endl;
    cout << setw(25) << left << "Second Quarter" << setw(10) << right << division.secondQuarterSales << endl;
    cout << setw(25) << left << "Third Quarter" << setw(10) << right << division.thirdQuarterSales << endl;
    cout << setw(25) << left << "Fourth Quarter" << setw(10) << right << division.fourthQuarterSales << endl;
    cout << setw(25) << left << "Total Annual" << setw(10) << right << division.totalAnnualSales << endl;
    cout << setw(25) << left << "Quarterly Average" << setw(10) << right << division.averageQuarterlySales << endl;
    cout << endl;
}

// showAllData function shows sales data for all divisions and quarters
void showAllData(DivisionData east, DivisionData west, DivisionData north, DivisionData south)
{
    double q1All = east.firstQuarterSales + west.firstQuarterSales + north.firstQuarterSales + south.firstQuarterSales;
    double q2All = east.secondQuarterSales + west.secondQuarterSales + north.secondQuarterSales + south.secondQuarterSales;
    double q3All = east.thirdQuarterSales + west.thirdQuarterSales + north.thirdQuarterSales + south.thirdQuarterSales;
    double q4All = east.fourthQuarterSales + west.fourthQuarterSales + north.fourthQuarterSales + south.fourthQuarterSales;
    double annualAll = q1All + q2All + q3All + q4All;
    double averageAll = annualAll / 4;
    
    cout << setprecision(2) << fixed;
    // Displays division headers
    cout << setw(25) << left << " " << setw(15) << right << east.divisionName << setw(15);
    cout << west.divisionName << setw(15) << north.divisionName << setw(15) << south.divisionName;
    cout << setw(15) << "All" << endl;
    // Horizontal division
    cout << setfill('=') << setw(100) << '=' <<  setfill(' ') << endl;    
    // Displays first quarter
    cout << setw(25) << left << "First Quarter" << setw(15) << right << east.firstQuarterSales;
    cout << setw(15) << west.firstQuarterSales << setw(15) << north.firstQuarterSales;
    cout << setw(15) << south.firstQuarterSales << setw(15) << q1All << endl;
    // Displays second quarter
    cout << setw(25) << left << "Second Quarter" << setw(15) << right << east.secondQuarterSales;
    cout << setw(15) << west.secondQuarterSales << setw(15) << north.secondQuarterSales;
    cout << setw(15) << south.secondQuarterSales << setw(15) << q2All << endl;
    // Displays third quarter
    cout << setw(25) << left << "Third Quarter" << setw(15) << right << east.thirdQuarterSales;
    cout << setw(15) << west.thirdQuarterSales << setw(15) << north.thirdQuarterSales;
    cout << setw(15) << south.thirdQuarterSales << setw(15) << q3All << endl;
    // Displays fourth quarter
    cout << setw(25) << left << "Fourth Quarter" << setw(15) << right << east.fourthQuarterSales;
    cout << setw(15) << west.fourthQuarterSales << setw(15) << north.fourthQuarterSales;
    cout << setw(15) << south.fourthQuarterSales << setw(15) << q4All << endl;
    // Horizontal division
    cout << setfill('-') << setw(100) << '-' <<  setfill(' ') << endl;
    // Displays total annual
    cout << setw(25) << left << "Total Annual" << setw(15) << right << east.totalAnnualSales;
    cout << setw(15) << west.totalAnnualSales << setw(15) << north.totalAnnualSales;
    cout << setw(15) << south.totalAnnualSales << setw(15) << annualAll << endl;
    // Horizontal division
    cout << setfill('-') << setw(100) << '-' <<  setfill(' ') << endl;
    // Displays averages
    cout << setw(25) << left << "Average" << setw(15) << right << east.averageQuarterlySales;
    cout << setw(15) << west.averageQuarterlySales << setw(15) << north.averageQuarterlySales;
    cout << setw(15) << south.averageQuarterlySales << setw(15) << averageAll << endl;
    
    cout << endl;
}