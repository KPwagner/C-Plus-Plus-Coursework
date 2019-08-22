/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 6 Challenge 8
 *  Coin Toss: Write a function named coinToss that simulates the tossing of a 
 *  coin. When you call the function, it should generate a random number in the 
 *  range of 1 through 2. If the random number is 1, the function should display 
 *  "heads." If the random number is 2, the function should display "tails." 
 *  Demonstrate the function in a program that asks the user how many times the 
 *  coin should be tossed, then simulates the tossing of the coin that number 
 *  of times.
 */

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <ctime>

using namespace std;

void coinToss();

int main()
{
    int num_tosses;
    unsigned seed = time(0); // Time variable for seeding random number generator
    srand(seed); // Uses time to see the random number generator
    
    cout << "This program simulates a coin toss.\n" << endl;
    cout << "How many times should the coin be tossed?" << endl;
    cin >> num_tosses;
//    cin.ignore(20, '\n');
    
    for (int i = 0; i < num_tosses; i++)
    {
        cout << "Toss #" << setw(6) << left << i + 1;
        coinToss();
    }
    
    cin.ignore();
    cin.get();
}

void coinToss()
{
    int random_number;
    
    random_number = rand() % 2 + 1; // Generates random number in the range of 1-2
    switch (random_number)
    {
        case 1:
            cout << "Heads" << endl;
            break;
        case 2:
            cout << "Tails" << endl;
            break;
        default:
            cout << "coinToss() did not generate a heads or a tails value." << endl;                   
            break;
    }
}