/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 4 Challenge 1
 *  Minimum/Maximum: Write a program that asks the user to enter two numbers. 
 *  The program should use the conditional operator to determine which number 
 *  is the smaller and which is the larger.
 */

# include <iostream>
using namespace std;

int main() {
    // integer numbers used to avoid rounding errors
    double number_1, number_2;
    
    cout << "Enter two numbers separated by a space:" << endl;
    cin >> number_1 >> number_2; // if user enters floats, output will be junk
    
    if (number_1 == number_2) {
        cout << "These two numbers are the same size. Neither is larger or smaller than the other." << endl;
    }
    else {
        cout << (number_1 > number_2 ? number_1 : number_2) << " is the larger number." << endl;
        cout << (number_1 < number_2 ? number_1 : number_2) << " is the smaller number." << endl;
    }
    
    cin.ignore();
    cin.get();
    return 0;
}