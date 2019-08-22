/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 15 Challenge 7
 *  PersonData and CustomerData Classes: Design a class named PersonData with 
 *  the following member variables:
 *      lastName
 *      firstName
 *      address
 *      city
 *      state
 *      zip
 *      phone
 * 
 *  Write the appropriate accessor and mutator functions for these member 
 *  variables.
 * 
 *  Next, design a class named CustomerData, which is derived from the 
 *  PersonData class. The CustomerData class should have the following member 
 *  variables:
 *      customerNumber
 *      mailingList
 * 
 *  The customerNumber variable will be used to hold a unique integer for each 
 *  customer. The mailingList variable should be a bool. It will be set to true 
 *  if the customer wishes to be on a mailing list, false if the customer does 
 *  not wish to be on a mailing list. Write appropriate accessor and mutator 
 *  functions for these member variables. Demonstrate an object of the 
 *  CustomerData class in a simple program.
 */

# include <iostream>
# include <string>
using namespace std;

class PersonData
{
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        int zip;
        string phone;
    public:
        // constructors
        PersonData()
        {
            lastName = "";
            firstName = "";
            address = "";
            city = "";
            state = "";
            zip = 0;
            phone = "";
        }
        
        PersonData(string ln, string fn, string add, string c, string s, int z, string ph)
        {
            lastName = ln;
            firstName = fn;
            address = add;
            city = c;
            state = s;
            zip = z;
            phone = ph;
        }
        
        // mutator functions
        void setLastName(string ln)
        { lastName = ln; }
        
        void setFirstName(string fn)
        { firstName = fn; }
        
        void setAddress(string add)
        { address = add; }
        
        void setCity(string c)
        { city = c; }
        
        void setState(string s)
        { state = s; }
        
        void setZip(int z)
        { zip = z; }
        
        void setPhone(string ph)
        { phone = ph; }
        
        // accessor functions
        string getLastName() const
        { return lastName; }
        
        string getFirstName() const
        { return firstName; }
        
        string getAddress() const
        { return address; }
        
        string getCity() const
        { return city; }
        
        string getState() const
        { return state; }
        
        int getZip() const
        { return zip; }
        
        string getPhone() const
        { return phone; }
        
        // display functions
        void displayPersonData() const
        {
            cout << "Last Name:\t\t" << getLastName() << endl;
            cout << "First Name:\t\t" << getFirstName() << endl;
            cout << "Address:\t\t" << getAddress() << endl;
            cout << "City:\t\t\t" << getCity() << endl;
            cout << "State:\t\t\t" << getState() << endl;
            cout << "Zip:\t\t\t" << getZip() << endl;
            cout << "Phone:\t\t\t" << getPhone() << endl;
        }
};

class CustomerData : public PersonData
{
    private:
        int customerNumber;
        bool mailingList;
    public:
        // constructors
        CustomerData() : PersonData()
        {
            customerNumber = 0;
            mailingList = false;
        }
        
        CustomerData(int num, bool mail, string ln, string fn, string add, string c, string s, int z, string ph) : PersonData(ln, fn, add, c, s, z, ph)
        {
            customerNumber = num;
            mailingList = mail;
        }
        
        // mutator functions
        void setCustomerNumber(int num)
        { customerNumber = num; }
        
        void setMailingList(bool mail)
        { mailingList = mail; }
        
        // accessor functions
        int getCustomerNumber() const
        { return customerNumber; }
        
        bool getMailingList() const
        { return mailingList; }
        
        // display functions
        void displayCustomerData() const
        {
            displayPersonData();
            cout << "Customer Number:\t" << getCustomerNumber() << endl;
            cout << "Mailing List:\t\t" << getMailingList() << endl;
        }
};

int main()
{
    // welcome message
    cout << "This program uses a class named 'CustomerData' derived from a class named 'PersonData'." << endl;
    
    cout << "\n\n";
    
    // demonstration
    cout << "To demonstrate these classes, a CustomerData object is created with the " << endl; 
    cout << "default constructor (no arguments)." << endl;
    cout << endl;
    cout << "Then, the data is displayed with a CustomerData display function that uses " << endl;
    cout << "other accessor and display functions from both classes." << endl;
    cout << endl;
    
    CustomerData noData;
    noData.displayCustomerData();
    
    cout << "\n\n";
    cout << "Press [Enter] to continue." << endl;
    cin.get();
    cout << endl;
    
    cout << "Next, a CustomerData object is created with all nine arguments passed to the " << endl;
    cout << "CustomerData constructor." << endl;
    cout << endl;
    cout << "Here is the result of calling CustomerData's display function:" << endl;
    cout << endl;
    
    CustomerData kyle(237, true, "Wagner", "Kyle", "5555 Elm St.", "Emmetsburg", "IA", 50536, "(712) 555-5555");
    kyle.displayCustomerData();
    
    
    // exit message
    cout << "\n\n";
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}
