/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 6 Challenge 1
 *  Markup: Write a program that asks the user to enter an item's wholesale 
 *  cost and its markup percentage. It should then display the item's retail 
 *  price. For example:
 * 
 *  > If an item's wholesale cost is 5.00 and its markup percentage is 
 *  100 percent, then the item's retail price is 10.00.
 * 
 *  > If an item's wholesale cost is 5.00 and its markup percentage is 
 *  50 percent, then the item's retail price is 7.50.
 *  
 *  The program should have a function name calculateRetail that receives the 
 *  wholesale cost and the markup percentage as arguments and returns the retail 
 *  price of the item.
 *  
 *  Input Validation: Do not accept negative values for either the wholesale 
 *  cost of the item or the markup percentage.
 *  
 */

# include <iostream>
# include <iomanip>
using namespace std;

// Function prototypes
double calculateRetail(double, double);


int main()
{
    // Declare variables
    double wholesale_cost, retail_price, markup;
    
    // Prompt user for input values
    cout << "This program calculates a retail price based on a wholesale cost and a markup percent." << endl;
    
    // Prompts user to reenter values if they enter a negative number
    do
    {
        cout << "\nWhat is the wholesale cost?" << endl;
        cin >> wholesale_cost;
        if (wholesale_cost < 0)
        {
            cout << "Wholesale cost cannot be less than 0." << endl;
        }
    } while (wholesale_cost < 0);
        
    do
    {
        cout << "\nWhat is the markup percent?" << endl;
        cin >> markup;
        if (markup < 0)
        {
            cout << "Markup percent cannot be less than 0." << endl;
        }
    } while (markup < 0);
    
    
    retail_price = calculateRetail(wholesale_cost, markup);
    cout << setfill('.');
    cout << endl;
    cout << setw(20) << left << "Wholesale cost";
    cout << setw(6) << right << setprecision(2) << fixed << wholesale_cost << endl;
    cout << setw(20) << left << "Markup percent";
    cout << setw(6) << right << setprecision(1) << fixed << markup << endl;
    cout << setw(20) << left << "Retail price";
    cout << setw(6) << right << setprecision(2) << fixed << retail_price << endl;
    
    cin.ignore();
    cin.get();
    return 0;
}

double calculateRetail(double cost, double markup)
{
    // Declare local variables
    double retail_price;
    
    // Check for negative value arguments
    if (cost < 0 || markup < 0)
    {
        cout << "Negative values not allowed as arguments for the calculateRetail function." << endl;
        return 0.0;
    }
    else
    {
        // Calculate and return retail price
        retail_price = cost * (1 + (markup/100));
        return retail_price;
    }   
}
