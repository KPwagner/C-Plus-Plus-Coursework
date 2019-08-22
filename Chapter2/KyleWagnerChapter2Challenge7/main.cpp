/*  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 2 Challenge 7
 *  Ocean Levels: Assuming the ocean's level is currently rising at about 
 *  1.5 millimeters per year, write a program that displays:
 *  - The number of millimeters higher than the current level that the ocean's 
 *    level will be in 5 years.
 *  - The number of millimeters higher than the current level that the ocean's 
 *    level will be in 7 years.
 *  - The number of millimeters higher than the current level that the ocean's 
 *    level will be in 10 years.
 */

# include <iostream>
using namespace std;

int main() {
    // Constant for annual rate of ocean level rising (in millimeters)
    const double ANNUAL_RATE_RISE = 1.5;
    
    // Variables for amount of ocean level rise over x number of years
    double five_year_rise = ANNUAL_RATE_RISE * 5;
    double seven_year_rise = ANNUAL_RATE_RISE * 7;
    double ten_year_rise = ANNUAL_RATE_RISE * 10;
    
    // Displays the calculated ocean level increases
    cout << "Predicted ocean level rise over time (in millimeters):" << endl;
    cout << "Five years\t" << five_year_rise << endl;
    cout << "Seven years\t" << seven_year_rise << endl;
    cout << "Ten years\t" << ten_year_rise << endl;
    
    cin.get();
    return 0;
}