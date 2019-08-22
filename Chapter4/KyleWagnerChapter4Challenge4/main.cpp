/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 4 Challenge 4
 *  Areas of Rectangles: The area of a rectangle is the rectangle's length times
 *  its width. Write a program that asks for the length and width of two 
 *  rectangles. The program should tell the user which rectangle has the greater 
 *  area, or if the areas are the same.
 */

# include <iostream>
using namespace std;

int main() {
    // Initialize variables
    double length_1, width_1, length_2, width_2, area_1, area_2;
    
    cout << "This program calculates and compares the area of two rectangles.\n" << endl;
    
    // Prompt user for length and width of first rectangle
    cout << "Enter the length and width (separated by a space) of the first rectangle:" << endl;
    cin >> length_1 >> width_1;
    
    // Prompt user for length and width of second rectangle
    cout << "Enter the length and width (separated by a space) of the second rectangle:" << endl;
    cin >> length_2 >> width_2;
    
    if (length_1 > 0 && length_2 > 0 && width_1 > 0 && width_2 > 0) {
        // Calculate areas of both rectangles
        area_1 = length_1 * width_1;
        area_2 = length_2 * width_2;

        if (area_1 == area_2) {
            cout << "\nThe area of the two rectangles is the same.";
        }
        else {
            cout << "\nThe area of the " << (area_1 > area_2 ?  "first" : "second");
            cout << " rectangle is bigger." << endl;
        }
    }
    else {
        cout << "\nNon-positive numbers are not allowed." << endl;
    }
    
    cin.ignore();
    cin.get();
    return 0;
}
