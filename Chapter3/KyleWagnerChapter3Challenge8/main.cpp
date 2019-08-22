/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 3 Challenge 8
 *  How Many Widgets?: The Yukon Widget Company manufactures widgets that weigh 
 *  12.5 pounds each. Write a program that calculates how many widgets are 
 *  stacked on a pallet, based on the total weight of the pallet. The program 
 *  should ask the user how much the pallet weighs by itself and with the 
 *  widgets stacked on it. It should then calculate and display the number of 
 *  widgets stacked on the pallet.
 */

# include <iostream>
# include <iomanip>
using namespace std;

int main() {
    // Constants
    const double WIDGET_WEIGHT = 12.5;
    
    // Variables
    double empty_pallet_weight, loaded_pallet_weight, num_widgets;
    int num_widgets_rounded;
    
    // Ask user for data
    cout << "This program calculates the number of widgets loaded on a pallet." << endl;
    cout << "Weight per widget is assumed to be " << WIDGET_WEIGHT << " pounds." << endl;
    cout << "\nWhat is the weight in pounds of an empty (unloaded) pallet?" << endl;
    cin >> empty_pallet_weight;
    cout << "\nWhat is the weight in pounds of the loaded pallet?" << endl;
    cin >> loaded_pallet_weight;
    
    // Calculate the number of widgets on the pallet
    num_widgets = (loaded_pallet_weight - empty_pallet_weight) / WIDGET_WEIGHT;
    num_widgets_rounded = static_cast<int>(num_widgets);
    
    // Display the result
    cout << "\nThere are " << num_widgets_rounded << " widgets stacked on the pallet." << endl;
    cout << "Note: displayed result (" << num_widgets_rounded <<  ") is rounded down to the nearest whole widget." << endl;
    cout << "Actual calculated result is " << num_widgets << endl;
    
    // cin.get() added here on Mr. Noord's request.
    // cin.ignore() seems to be necessary to ignore the \n keyboard buffer.
    cin.ignore();
    cin.get();
    return 0;
}