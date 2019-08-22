/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 13 Challenge 3
 *  Car Class: Write a class named Car that has the following member variables:
 *      yearModel - an int that holds the car's year model
 *      make - a string that holds the make of the car
 *      speed - an int that holds the car's current speed
 * 
 *  In addition, the class should have the following constructor and other 
 *  member functions:
 *      Constructor --  The constructor should accept the car's year model and 
 *                      make as arguments. These values should be assigned to 
 *                      the object's yearModel and make member variables. The 
 *                      constructor should also assign 0 to the speed member 
 *                      variables.
 *      Accessor -----  appropriate accessor functions to get the values stored 
 *                      in an object's yearModel, make, and speed member 
 *                      variables
 *      accelerate ---  The accelerate function should add 5 to the speed member 
 *                      variable each time it is called.
 *      brake --------  The brake function should subtract 5 from the speed 
 *                      member variable each time it is called.
 * 
 *  Demonstrate the class in a program that creates a Car object, then calls the 
 *  accelerate function five times. After each call to the accelerate function, 
 *  get the current speed of the car and display it. Then call the brake 
 *  function five times. After each call to the brake function, get the current 
 *  speed of the car and display it.
 */

# include <iostream>
# include <string>
using namespace std;

// Date class declaration
class Car
{
    private:
        int yearModel;
        string make;
        int speed;
    public:
        Car(int, string);
        int getYearModel() const;
        string getMake() const;
        int getSpeed() const;
        void accelerate();
        void brake();
        
};

Car::Car(int y, string m)
{
    yearModel = y;
    make = m;
    speed = 0;
}

int Car::getYearModel() const
{
    return yearModel;
}

string Car::getMake() const
{
    return make;
}

int Car::getSpeed() const
{
    return speed;
}

void Car::accelerate()
{
    cout << "Accelerating................." << endl;
    speed += 5;
}

void Car::brake()
{
    cout << "Braking......................" << endl;
    speed -=5;
    if (speed < 0)
        speed = 0;
}


int main()
{
    // Welcome message
    cout << "This program uses a class named Car to simulate accelerating and braking." << endl;
    cout << endl;
    
    // creates Car object and displays attributes
    Car ford(1969, "Ford");
    cout << "New car object created: " << endl;
    cout << "\tYear: " << ford.getYearModel() << endl;
    cout << "\tMake: " << ford.getMake() << endl;
    cout << "\tSpeed: " << ford.getSpeed() << endl;
    cout << endl;
    
    // calls accelerate member function five times, displaying speed after each call
    for (int i = 0; i < 5; i++)
    {
        ford.accelerate();
        cout << "Current Speed of " << ford.getMake() << ": " << ford.getSpeed() << endl;
    }
    cout << "\n\n";
    
    // calls brake member function five times, displaying speed after each call
    for (int i = 0; i < 5; i++)
    {
        ford.brake();
        cout << "Current Speed of " << ford.getMake() << ": " << ford.getSpeed() << endl;
    }
    cout << "\n\n";
    
    
    // Exit message
    cout << "Press [Enter] to exit this program." << endl;
    cin.get();
    return 0;
}

