/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 11 Challenge 7
 *  Customer Accounts: Write a program that uses a structure to store the 
 *  following data about a customer account:
 *      Name
 *      Address
 *      City, State, and ZIP
 *      Telephone Number
 *      Account Balance
 *      Date of Last Payment
 *  
 * The program should use an array of at least 10 structures. It should let the 
 *  user enter data into the array, change the contents of any element, and 
 *  display all the data stored in the array. The program should have a 
 *  menu-driven user interface.
 * 
 *  Input Validation: When the data for a new account is entered, be sure the 
 *  user enters data for all the fields. No negative account balances should be 
 *  entered.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// Abstract data type declarations
struct Account 
{
    bool active;
    string name;
    string streetAddress;
    string cityStateZip;
    string telephone;
    double accountBalance;
    string dateLastPayment;
};

// Function prototypes
void showMenu();
int getMenuSelection(int, int);
void handleMenuSelection(Account[], int, int);
void showAllCustomerData(Account[], int);
int getNewCustomerIndex(Account[], int);
void addNewCustomer(Account[], int);
int getCustomerNumber();
void removeCustomer(Account[]);
void editCustomer(Account[]);

int main()
{
    // Welcome message
    cout << "This program stores data about customer accounts." << endl;
    cout << "Note: you may only store a maximum of 10 customer accounts." << endl;
    cout << endl;
    
    // Variables
    const int NUM_CUSTOMERS = 10;
    // Account array, initialized with 2 entries for testing.
    Account customers[NUM_CUSTOMERS] = {
        {true, "Doe, John", "1234 Merryview Lane", "Pleasantville, IN, 30354", "818-745-9723", 1234.56, "5/22/19"},
        {true, "Cullins, Samantha", "3435 Elm St", "Farmville, IL, 40567", "787-345-2645", 2345.67, "6/1/19"}
    };
    int menuSelection;
    
    // Continues to prompt user for a menu selection until they request to exit the program
    do
    {
        showMenu();
        menuSelection = getMenuSelection(1, 5);
        handleMenuSelection(customers, NUM_CUSTOMERS, menuSelection);
    } while(menuSelection != 5);
    
    
    
    // Exit message
    cout << "Press [Enter] to exit this program." << endl;
    cin.ignore(20,'\n');
    cin.get();
}

// showMenu function displays the MAIN MENU, with its 5 options
void showMenu()
{
    int userSelection;
    cout << "MAIN MENU:" << endl;
    cout << "1. Show All Customer Account Data" << endl;
    cout << "2. Add a New Customer Record" << endl;
    cout << "3. Remove an Existing Customer Record" << endl;
    cout << "4. Edit an Existing Customer Record" << endl;
    cout << "5. Exit Program" << endl;
    cout << "\nMake a selection (1-5):  ";
}

// getMenuSelection function accepts an int from the user, and returns value
// Valid user input is constrained to min/max range defined by function arguments
int getMenuSelection(int minValue, int maxValue)
{
    int userSelection;
    do
    {
        cin >> userSelection;        
        if(!cin)
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
        if (userSelection < minValue || userSelection > maxValue)
        {
            cout << "*** enter a number " << minValue << "-" << maxValue << " ***" << endl;
        }
    } while (userSelection < 1 || userSelection > 5);
    cout << endl;
    return userSelection;
}

// handleMenuSelection function uses an int argument to provide different menu functionality
void handleMenuSelection(Account customers[], int size, int selection)
{
    switch(selection)
    {
        case 1:
            showAllCustomerData(customers, size);
            break;
        case 2:
        {
            int newCustomerIndex = getNewCustomerIndex(customers, size);
            addNewCustomer(customers, newCustomerIndex);
            break;
        }            
        case 3:
            removeCustomer(customers);
            break;
        case 4:
            editCustomer(customers);
            break;
        case 5:
            cout << "Exiting Program..................." << endl;
            break;
    }
}

// showAllCustomerData function shows all fields all active customers
void showAllCustomerData(Account customers[], int size)
{
    int colOneWidth = 25;
    int colTwoWidth = 30;
    for (int index = 0; index < size; index++)
    {
        if(customers[index].active)
        {
            cout << "CUSTOMER NUMBER " << (index + 1) << endl;
            cout << setw(colOneWidth) << left << "Name:" << setw(colTwoWidth) << right << customers[index].name << endl;
            cout << setw(colOneWidth) << left << "Street Address:" << setw(colTwoWidth) << right << customers[index].streetAddress << endl;
            cout << setw(colOneWidth) << left << "City, State, and ZIP:" << setw(colTwoWidth) << right << customers[index].cityStateZip << endl;
            cout << setw(colOneWidth) << left << "Telephone:" << setw(colTwoWidth) << right << customers[index].telephone << endl;
            cout << setw(colOneWidth) << left << "Account Balance:" << setw(colTwoWidth) << right << setprecision(2) << fixed << customers[index].accountBalance << endl;
            cout << setw(colOneWidth) << left << "Date of Last Payment:" << setw(colTwoWidth) << right << customers[index].dateLastPayment << endl;
            cout << endl;
        }
    }
    
    cout << "\nPress [Enter] to return to the main menu." << endl;
    cin.ignore(20, '\n');
    cin.get();
}

// getNewCustomerIndex function returns the index of the first available non-active
// user in an Account array
int getNewCustomerIndex(Account customers[], int size)
{
    // Tracks the first available index for a new customer entry
    for (int index = 0; index < size; index++)
    {
        if (!customers[index].active)
            return index;
    }
    return -1;  // -1 is default value for when no inactive customers are available
}

// addNewCustomer function prompts user to enter data for a new user,
// this data is then stored in the Account structure
void addNewCustomer(Account customers[], int newCustomerIndex)
{
    double accountBalance;
    
    // Sets active field to true
    customers[newCustomerIndex].active = true;
    
    cout << "You must complete all fields to add a new customer." << endl;
    
    // Gets customer name
    cout << "Customer Name (Last, First):  ";
    cin.ignore(20, '\n');
    getline(cin, customers[newCustomerIndex].name);
    
    // Gets street address
    cout << "Street Address:  ";
    getline(cin, customers[newCustomerIndex].streetAddress);
    
    // Gets city, state, and zip
    cout << "City, State ZIP code:  ";
    getline(cin, customers[newCustomerIndex].cityStateZip);
    
    // Gets telephone
    cout << "Telephone Number:  ";
    getline(cin, customers[newCustomerIndex].telephone);
    
    // Gets account balance
    cout << "Current Account Balance:  ";
    // Continues to prompt user for input if they enter a negative value
    do
    {
        cin >> customers[newCustomerIndex].accountBalance;
        // cin.clear and cin.ignore help to prevent errors from bad user input
        cin.clear();
        cin.ignore(20, '\n');
        if (customers[newCustomerIndex].accountBalance < 0)
            cout << "*** enter a non-negative number for account balance ***" << endl;
    } while (customers[newCustomerIndex].accountBalance < 0);
    
    
    // Gets date of last payment
    cout << "Date of Last Payment:  ";
    getline(cin, customers[newCustomerIndex].dateLastPayment);
    
    cout << endl;
    
    cout << "Press [Enter] to return to main menu." << endl;
    cin.get();
}

// getCustomerNumber function prompts user for an int representing a customer
// this int value is then returned.
int getCustomerNumber()
{
    int customerNumber;
    cout << "Enter a customer number:  ";
    cin >> customerNumber;
    return customerNumber;
}

// removeCustomer function prompts the user to select a customer number
// this customer number is changed from active value of true to active value of false
void removeCustomer(Account customers[])
{
    int customerNumber;
    
    cout << "REMOVE CUSTOMER" << endl;
    customerNumber = getCustomerNumber();
    customers[customerNumber - 1].active = false;
    cout << "Customer number " << customerNumber << " was removed." << endl;
    
    cout << "\nPress [Enter] to return to the main menu." << endl;
    cin.ignore(20,'\n');
    cin.get();
}

// editCustomer function uses a menu system to prompt the user to make an edit
// to any of the records of an Account structure in the array argument
void editCustomer(Account customers[])
{
    int fieldNumber;
    int customerNumber;
    
    cout << "EDIT CUSTOMER" << endl;
    customerNumber = getCustomerNumber();
    
    cout << "\nYou can edit any of the following fields:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Street Address" << endl;
    cout << "3. City, State, and Zip" << endl;
    cout << "4. Telephone" << endl;
    cout << "5. Account Balance" << endl;
    cout << "6. Date of Last Payment" << endl;
    cout << "\nEnter the number of the field you want to edit:  ";
    
    fieldNumber = getMenuSelection(1,6);
    cin.ignore(20, '\n');
    
    switch(fieldNumber)
    {
        case 1:
        {
            string oldName = customers[customerNumber - 1].name;
            cout << "Enter a new name for customer number " << customerNumber << ":  ";
            getline(cin, customers[customerNumber - 1].name);
            cout << "Customer number " << customerNumber << " name record changed." << endl;
            cout << "Old Record: " << oldName << endl;
            cout << "New Record: " << customers[customerNumber - 1].name << endl;            
            cout << endl;
            cout << "Press [Enter] to return to main menu." << endl;
            cin.get();
            break;
        }
            
        case 2:
        {
            string oldStreetAddress = customers[customerNumber - 1].streetAddress;
            cout << "Enter a new street address for customer number " << customerNumber << ":  ";
            getline(cin, customers[customerNumber - 1].streetAddress);
            cout << "Customer number " << customerNumber << " street address record changed." << endl;
            cout << "Old Record: " << oldStreetAddress << endl;
            cout << "New Record: " << customers[customerNumber - 1].streetAddress << endl;
            cout << endl;
            cout << "Press [Enter] to return to main menu." << endl;
            cin.get();
            break;
        }
        
        case 3:
        {
            string oldCityStateZip = customers[customerNumber - 1].cityStateZip;
            cout << "Enter a new city, state, and zip code for customer number " << customerNumber << ":  ";
            getline(cin, customers[customerNumber - 1].cityStateZip);
            cout << "Customer number " << customerNumber << " city, state and zip code record changed." << endl;
            cout << "Old record: " << oldCityStateZip << endl;
            cout << "New record: " << customers[customerNumber - 1].cityStateZip << endl;
            cout << endl;
            cout << "Press [Enter] to return to main menu." << endl;
            cin.get();
            break;
        }
        
        case 4:
        {
            string oldTelephone = customers[customerNumber - 1].telephone;
            cout << "Enter a new telephone number for customer number " << customerNumber << ":  ";
            getline(cin, customers[customerNumber - 1].telephone);
            cout << "Customer number " << customerNumber << " telephone record changed." << endl;
            cout << "Old Record: " << oldTelephone << endl;
            cout << "New Record: " << customers[customerNumber - 1].telephone << endl;
            cout << endl;
            cout << "Press [Enter] to return to main menu." << endl;
            cin.get();
            break;
        }
        
        case 5:
        {
            double oldAccountBalance = customers[customerNumber - 1].accountBalance;
            cout << "Enter a new account balance for customer number " << customerNumber << ":  ";            
            // Continues to prompt user for input if they enter a negative value
            do
            {
                cin >> customers[customerNumber - 1].accountBalance;
                // cin.clear and cin.ignore help to prevent errors from bad user input
                cin.clear();
                cin.ignore(20, '\n');
                if (customers[customerNumber - 1].accountBalance < 0)
                    cout << "*** enter a non-negative number for account balance ***" << endl;
            } while (customers[customerNumber - 1].accountBalance < 0);
            cout << "Customer number " << customerNumber << " account balance record changed." << endl;
            cout << "Old Record: " << oldAccountBalance << endl;
            cout << "New Record: " << customers[customerNumber - 1].accountBalance << endl;
            cout << endl;
            cout << "Press [Enter] to return to main menu." << endl;
            cin.get();
            break;
        }
        
        case 6:
        {
            string oldDateLastPayment = customers[customerNumber - 1].dateLastPayment;
            cout << "Enter a new date of last payment for customer number " << customerNumber << ":  ";
            getline(cin, customers[customerNumber - 1].dateLastPayment);
            cout << "Customer number " << customerNumber << " date of last payment record changed." << endl;
            cout << "Old Record: " << oldDateLastPayment << endl;
            cout << "New Record: " << customers[customerNumber - 1].dateLastPayment << endl;
            cout << endl;
            cout << "Press [Enter] to return to main menu." << endl;
            cin.get();
            break;
        }
    }
}