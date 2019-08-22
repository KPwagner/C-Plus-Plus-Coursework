/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 13 Challenge 5
 *  Retail Item Class: Write a class named RetailItem that holds data about an 
 *  item in a retail store. The class should have the following member 
 *  variables:
 *      description  -  a string that holds a brief description of the item
 *      unitsOnHand  -  an int that holds the number of units currently in inventory
 *      price        -  a double that holds the item's retail price
 *  
 *  Write a constructor that accepts arguments for each member variable, 
 *  appropriate mutator functions that store values in these member variables, 
 *  and accessor functions that return the values in these member variables. 
 *  Once you have written the class, write a separate program that creates 
 *  three RetailItem objects and stores the following data in them:
 * 
 *                  Description         Units on Hand       Price
 *      --------------------------------------------------------- 
 *      Item #1     Jacket              12                  59.95
 *      Item #2     Designer Jeans      40                  34.95
 *      Item #3     Shirt               20                  24.95
 */

# include <iostream>
# include <iomanip>
# include <string>
# include "RetailItem.h"
using namespace std;

int main()
{
    // variables for iomanip formatting
    int const COL_ONE_WIDTH = 20;
    int const COL_TWO_WIDTH = 20;
    int const COL_THREE_WIDTH = 15;
    int const COL_FOUR_WIDTH = 10;
    int horizontalLineWidth = COL_ONE_WIDTH + COL_TWO_WIDTH + COL_THREE_WIDTH + COL_FOUR_WIDTH;
    
    // welcome message
    cout << "This program uses a class named RetailItem to store information about " << endl;
    cout << "items in a retail store." << endl;
    cout << endl;
    
    // explains and creates the jacket object
    cout << "JACKET OBJECT" << endl;
    cout << "Using constructor arguments to create a RetailItem object with the following attributes:" << endl;
    cout << "\tDescription:     Jacket" << endl;
    cout << "\tUnits On Hand:   12" << endl;
    cout << "\tPrice:           59.95" << endl;
    cout << "\n\n";
    RetailItem jacket("Jacket", 12, 59.95);
    
    
    // explains and creates the designerJeans object
    cout << "DESIGNER JEANS OBJECT" << endl;
    cout << "Creating a RetailItem object named designerJeans with no initialized attributes." << endl;
    cout << endl;
    RetailItem designerJeans;
    
    // explains and sets the designerJeans object attributes with member functions
    cout << "Using the setDescription mutator member function to set the value of" << endl;
    cout << "the description attribute to string value 'Designer Jeans'." << endl;
    cout << endl;
    designerJeans.setDescription("Designer Jeans");
    
    cout << "Using the setUnitsOnHand mutator member function to set the value of" << endl;
    cout << "the unitsOnHand attribute to int value 40." << endl;
    cout << endl;
    designerJeans.setUnitsOnHand(40);
    
    cout << "Using the setPrice mutator member function to set the value of" << endl;
    cout << "the price attribute to double value 34.95." << endl;
    cout << "\n\n";
    designerJeans.setPrice(34.95);
    
    
    // explains and creates the shirt object
    cout << "SHIRT OBJECT" << endl;
    cout << "Creating a RetailItem object named shirt with no initialized attributes." << endl;
    cout << endl;
    RetailItem shirt;
    
    // explains and sets the object attributes with member functions
    cout << "Using the setDescription mutator member function to set the value of" << endl;
    cout << "the description attribute to string value 'Shirt'." << endl;
    cout << endl;
    shirt.setDescription("Shirt");
    
    cout << "Using the setUnitsOnHand mutator member function to set the value of" << endl;
    cout << "the unitsOnHand attribute to int value 20." << endl;
    cout << endl;
    shirt.setUnitsOnHand(20);
    
    cout << "Using the setPrice mutator member function to set the value of" << endl;
    cout << "the price attribute to double value 24.95." << endl;
    cout << "\n\n";
    shirt.setPrice(24.95);
    
    
    cout << "DISPLAY TABLE" << endl;
    cout << "The following table uses accessor member functions to display all RetailItem attributes:" << endl;
    cout << endl;
    
    // shows a complete table with all RetailItem objects data
    cout << setw(COL_ONE_WIDTH) << left << ' ' << setw(COL_TWO_WIDTH) << "Description" << setw(COL_THREE_WIDTH) << "Units On Hand" << setw(COL_FOUR_WIDTH) << "Price" << endl;
    cout << setw(horizontalLineWidth) << setfill('-') << '-' << setfill(' ') << endl;
    cout << setw(COL_ONE_WIDTH) << left << "RetailItem #1" << setw(COL_TWO_WIDTH) << jacket.getDescription() << setw(COL_THREE_WIDTH) << jacket.getUnitsOnHand() << setw(COL_FOUR_WIDTH) << jacket.getPrice() << endl;
    cout << setw(COL_ONE_WIDTH) << left << "RetailItem #2" << setw(COL_TWO_WIDTH) << designerJeans.getDescription() << setw(COL_THREE_WIDTH) << designerJeans.getUnitsOnHand() << setw(COL_FOUR_WIDTH) << designerJeans.getPrice() << endl;
    cout << setw(COL_ONE_WIDTH) << left << "RetailItem #3" << setw(COL_TWO_WIDTH) << shirt.getDescription() << setw(COL_THREE_WIDTH) << shirt.getUnitsOnHand() << setw(COL_FOUR_WIDTH) << shirt.getPrice() << endl;
    cout << "\n\n";
    
    // exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}