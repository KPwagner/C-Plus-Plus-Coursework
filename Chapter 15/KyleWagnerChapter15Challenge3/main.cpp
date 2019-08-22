/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 15 Challenge 3
 *  Team Leader Class: In a particular factory, a team leader is an hourly paid 
 *  production worker who leads a small team. In addition to hourly pay, team 
 *  leaders earn a fixed monthly bonus. Team leaders are required to attend a 
 *  minimum number of hours of training per year. Design a TeamLeader class that 
 *  extends the ProductionWorker class you designed in Programming Challenge 1. 
 *  The TeamLeader class should have member variables for the monthly bonus 
 *  amount, the required number of training hours, and the number of training 
 *  hours that the team leader has attended. Write one or more constructors and 
 *  the appropriate accessor and mutator functions for the class. Demonstrate 
 *  the class by writing a program that uses a TeamLeader object.
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

class TeamLeader : public ProductionWorker
{
    private:
        double monthlyBonus;
        double requiredTrainingHours;
        double trainingHoursAttended;
    public:
        // constructors
        TeamLeader()
        {
            monthlyBonus = 0.0;
            requiredTrainingHours = 0.0;
            trainingHoursAttended = 0.0;
        }
        
        TeamLeader(double bonus, double training, double attended)
        {
            monthlyBonus = bonus;
            requiredTrainingHours = training;
            trainingHoursAttended = attended;
        }
        
        TeamLeader( double bonus, double training, double attended,
                    int s, double pr, string n, int num, string hd)
                    : ProductionWorker (s, pr, n, num, hd)
        {
            monthlyBonus = bonus;
            requiredTrainingHours = training;
            trainingHoursAttended = attended;
        }
        
        // mutator functions
        void setMonthlyBonus(double bonus)
        {
            monthlyBonus = bonus;
        }
        
        void setRequiredTrainingHours(double training)
        {
            requiredTrainingHours = training;
        }
        
        void setTrainingHoursAttended(double attended)
        {
            trainingHoursAttended = attended;
        }
        
        // accessor functions
        double getMonthlyBonus() const
        {
            return monthlyBonus;
        }
        
        double getRequiredTrainingHours() const
        {
            return requiredTrainingHours;
        }
        
        double getTrainingHoursAttended() const
        {
            return trainingHoursAttended;
        }
        
};



int main()
{   
    // welcome message
    cout << "This program uses three classes:" << endl;
    cout << "a class named 'ProductionWorker, derived from a class named 'Employee'," << endl;
    cout << "and a class named 'TeamLeader', derived from the ProductionWorker class." << endl;
    
    cout << "\n\n";
    
    // demonstration
    cout << "To demonstrate the classes, I created a TeamLeader object with " << endl;
    cout << "the following data passed to the TeamLeader constructor:" << endl;
    cout << endl;
    cout << "\tmonthlyBonus\t\t\t1245.56" << endl;
    cout << "\trequiredTrainingHours\t\t4" << endl;
    cout << "\ttrainingHoursAttended\t\t2.5" << endl;
    cout << "\tshift:\t\t\t\t1" << endl;
    cout << "\thourlyPayRate:\t\t\t22.56" << endl;
    cout << "\tname:\t\t\t\t\"Kyle Wagner\"" << endl;
    cout << "\tnumber:\t\t\t\t237" << endl;
    cout << "\thireDate:\t\t\t\"4/23/17\"" << endl;    
    TeamLeader kyle(1245.56, 4, 2.5, 1, 22.56, "Kyle Wagner", 237, "4/23/17");
    
    cout << "\n\n";
    
    cout << "Here is the data displayed, using accessor functions:" << endl;
    cout << endl;
    cout << "\tname:\t\t\t\t" << kyle.getName() << endl;
    cout << "\tnumber:\t\t\t\t" << kyle.getNumber() << endl;
    cout << "\thireDate:\t\t\t" << kyle.getHireDate() << endl;
    cout << "\tshift:\t\t\t\t" << kyle.getShift() << endl;
    cout << "\thourlyPayRate:\t\t\t" << kyle.getHourlyPayRate() << endl;    
    cout << "\tmonthlyBonus\t\t\t" << kyle.getMonthlyBonus() << endl;
    cout << "\trequiredTrainingHours\t\t" << kyle.getRequiredTrainingHours() << endl;
    cout << "\ttrainingHoursAttended\t\t" << kyle.getTrainingHoursAttended() << endl;
    cout << endl;
    cout << "Note: some accessor functions are enabled by the 'public' base class access specification." << endl;
            
    cout << "\n\n";
    
    // exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

