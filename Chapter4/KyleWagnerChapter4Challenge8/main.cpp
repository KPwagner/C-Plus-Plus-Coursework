/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 4 Challenge 8
 *  Color Mixer: The colors red, blue, and yellow are known as primary colors 
 *  because they cannot be made by mixing other colors. When you mix primary 
 *  colors, you get a secondary color, as shown here:
 * 
 *  When you mix red and blue, you get purple.
 *  When you mix red and yellow, you get orange.
 *  When you mix blue and yellow, you get green.
 * 
 *  Write a program that prompts the user to enter the names of two primary 
 *  colors to mix. If the user enters anything other than "red", "blue", 
 *  or "yellow", the program should display an error message. Otherwise, the 
 *  program should display the name of the secondary color that results by 
 *  mixing two primary colors.
 */

# include <iostream>
# include <string>
using namespace std;

int main() {
    // Initialize variables
    string primary_1, primary_2, combined_primary_colors;
    
    cout << "This program outputs a secondary color, based on the input of two primary colors.\n" << endl;
    
    // Prompt user for two primary colors as input
    cout << "Enter two primary colors (red, blue, or yellow) separated by a space:" << endl;
    cin >> primary_1 >> primary_2;
    cout << endl;
    
    // Check if input is a valid primary color (red, blue, yellow)
    if (primary_1 == primary_2) {
        cout << "You entered the same color twice." << endl;
        cout << "Please try again, entering two different primary colors." << endl;
    }
    else if (primary_1 != "red" && primary_1 != "blue" && primary_1 != "yellow") {
        cout << "The first color your entered was not red, blue, or yellow." << endl;
        cout << "Please try again, entering a valid primary color." << endl;
    }
    else if (primary_2 != "red" && primary_2 != "blue" && primary_2 != "yellow") {
        cout << "The second color your entered was not red, blue, or yellow." << endl;
        cout << "Please try again, entering a valid primary color." << endl;
    }
    else {
        combined_primary_colors = primary_1 + primary_2;
        if (combined_primary_colors == "redblue" || combined_primary_colors == "bluered") {
            cout << "PURPLE" << endl;
            cout << "The secondary color that results from mixing red and blue is purple." << endl;
        }
        else if (combined_primary_colors == "redyellow" || combined_primary_colors == "yellowred") {
            cout << "ORANGE" << endl;
            cout << "The secondary color that results from mixing red and yellow is orange." << endl;
        }
        else if (combined_primary_colors == "blueyellow" || combined_primary_colors == "yellowblue") {
            cout << "GREEN" << endl;
            cout << "The secondary color that results from mixing blue and yellow is green." << endl;
        }
    }
    
    cin.ignore();
    cin.get();
    return 0;
}
