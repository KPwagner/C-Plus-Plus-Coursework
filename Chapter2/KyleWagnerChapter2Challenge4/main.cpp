/*  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 2 Programming Challenge 4
 *  Restaurant Bill: Write a program that computes the tax and tip on a 
 *  restaurant bill for a patron with a $88.67 meal charge. The tax should be 
 *  6.75 percent of the meal cost. the tip should be 20 percent of the total 
 *  after adding the tax. Display the meal cost, tax amount, tip amount, and 
 *  total bill on screen.
 */

# include <iostream>
using namespace std;

int main() {
    // Constants for tax, tip, and meal charge
    const double TAX = 0.0675;
    const double TIP = 0.20;
    const double MEAL_CHARGE = 88.67;
    
    // Variables
    double tax_amount = MEAL_CHARGE * TAX;
    double tip_amount = (MEAL_CHARGE + tax_amount) * TIP;
    double total_bill = MEAL_CHARGE + tax_amount + tip_amount;
    
    // Displays the calculated amounts
    cout << "Meal Cost\t$" << MEAL_CHARGE << endl;
    cout << "Tax Amount\t$" << tax_amount << endl;
    cout << "Tip Amount\t$" << tip_amount << endl;
    cout << "----------\t--------" << endl;
    cout << "Total Bill\t$" << total_bill << endl;
    
    cin.get();
    return 0;
}

