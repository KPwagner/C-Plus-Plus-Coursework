/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 15 Challenge 1
 *  Employee and Production Worker Classes: Design a class named Employee. The 
 *  class should keep the following information:
 *      * Employee Name
 *      * Employee Number
 *      * Hire Date
 * 
 *  Write one or more constructors, and the appropriate accessor and mutator 
 *  functions, for the class.
 * 
 *  Next, write a class named ProductionWorker that is derived from the Employee 
 *  class. The ProductionWorker class should have member variables to hold the 
 *  following information:
 *      * Shift (an integer)
 *      * Hourly Pay Rate (a double)
 * 
 *  The workday is divided into two shifts: day and night. The shift variable 
 *  will hold an integer value representing the shift that the employee works. 
 *  The day shift is shift 1, and the night shift is shift 2. Write one or more 
 *  constructors, and the appropriate accessor and mutator functions, for the 
 *  class. Demonstrate the classes by writing a program that uses a 
 *  ProductionWorker object.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;


class Employee
{
    private:
        string name;
        int number;
        string hireDate;
    public:
        // constructors
        Employee()
        {
            name = "";
            number = 0;
            hireDate = "";
        }

        Employee(string n, int num, string hd)
        {
            name = n;
            number = num;
            hireDate = hd;
        }

        // mutator member functions
        void setName(string n)
        {
            name = n;
        }

        void setNumber(int n)
        {
            number = n;
        }

        void setHireDate(string hd)
        {
            hireDate = hd;
        }

        // accessor member functions
        string getName() const
        {
            return name;
        }

        int getNumber() const
        {
            return number;
        }

        string getHireDate() const
        {
            return hireDate;
        }
};

class ProductionWorker : public Employee
{
    private:
        int shift;
        double hourlyPayRate;
    public:
        // constructors
        ProductionWorker()
        {
            shift = 0;
            hourlyPayRate = 0.0;
        }
        
        ProductionWorker(int s, double pr)
        {
            shift = s;
            hourlyPayRate = pr;
        }
        
        ProductionWorker(int s, double pr, string n, int num, string hd) : Employee(n, num, hd)
        {
            shift = s;
            hourlyPayRate = pr;
        }
        
        // mutator functions
        void setShift(int s)
        {
            shift = s;
        }
        
        void setHourlyPayRate(double pr)
        {
            hourlyPayRate = pr;
        }
        
        // accessor functions
        int getShift() const
        {
            return shift;
        }
        
        double getHourlyPayRate() const
        {
            return hourlyPayRate;
        }
    
};


int main()
{   
    // welcome message
    cout << "This program uses two classes: a base class named 'Employee', and a derived class " << endl;
    cout << "named 'ProductionWorker'." << endl;
    cout << "\n\n";
    
    
    // demonstration
    cout << "To demonstrate the classes, I created a ProductionWorker object with " << endl;
    cout << "the following data passed to the ProductionWorker constructor:" << endl;
    cout << "\tshift:\t\t\t1" << endl;
    cout << "\thourlyPayRate:\t\t14.75" << endl;
    cout << "\tname:\t\t\t\"Kyle Wagner\"" << endl;
    cout << "\tnumber:\t\t\t237" << endl;
    cout << "\thireDate:\t\t\"5/3/18\"" << endl;
    ProductionWorker kyle(1, 14.75, "Kyle Wagner", 237, "5/3/18");
    
    cout << "\n\n";
    
    cout << "Here is the data displayed, using accessor functions:" << endl;
    cout << "\tname:\t\t\t" << kyle.getName() << endl;
    cout << "\tnumber:\t\t\t" << kyle.getNumber() << endl;
    cout << "\thireDate:\t\t" << kyle.getHireDate() << endl;
    cout << "\tshift:\t\t\t" << kyle.getShift() << endl;
    cout << "\thourlyPayRate:\t\t" << kyle.getHourlyPayRate() << endl;
    cout << endl;
    cout << "Note: some accessor functions are enabled by the 'public' base class access specification." << endl;
    
    cout << "\n\n";
            
    
    // exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

