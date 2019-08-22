/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 13 Challenge 7
 *  TestScores Class: Design a TestScores class that has member variables to 
 *  hold three test scores. The class should have a constructor, accessor, and 
 *  mutator functions for the test score fields and a member function that 
 *  returns the average of the test scores. Demonstrate the class by writing a 
 *  separate program that creates an instance of the class. The program should 
 *  ask the user to enter three test scores, which are stored in the TestScores 
 *  object. Then the program should display the average of the scores, as 
 *  reported by the TestScores object.
 */

# include <iostream>
# include <iomanip>
# include <string>
# include "TestScores.h"
using namespace std;


int main()
{
    // welcome message
    cout << "This program uses a class named TestScores to store three test scores." << endl;
    cout << endl;
    cout << "You will be prompted to enter three test scores. These scores will then " << endl;
    cout << "be stored in a TestScores object. The object will also be used to calculate " << endl;
    cout << "the average of the three scores." << endl;
    cout << endl;
    
    // variables for user input
    double scoreOne, scoreTwo, scoreThree;
    
    // initializes a TestScores object
    TestScores math;
    
    // collects the first score from the user, must be in range of 0-100
    do
    {
        cout << "Enter the first test score:  ";
        cin >> scoreOne;
        cin.clear();
        cin.ignore(256, '\n');
        if (scoreOne < 0 || scoreOne > 100)
            cout << "*** enter a number in the range of 0-100 ***" << endl;
    } while (scoreOne < 0 || scoreOne > 100);
    cout << endl;
    math.setScoreOne(scoreOne);
    
    // collects the second score from the user, must be in range of 0-100
    do
    {
        cout << "Enter the second test score:  ";
        cin >> scoreTwo;
        cin.clear();
        cin.ignore(256, '\n');
        if (scoreTwo < 0 || scoreTwo > 100)
            cout << "*** enter a number in the range of 0-100 ***" << endl;
    } while (scoreTwo < 0 || scoreTwo > 100);
    cout << endl;
    math.setScoreTwo(scoreTwo);
    
    // collects the third score from the user, must be in range of 0-100
    do
    {
        cout << "Enter the third test score:  ";
        cin >> scoreThree;
        cin.clear();
        cin.ignore(256, '\n');
        if (scoreThree < 0 || scoreThree > 100)
            cout << "*** enter a number in the range of 0-100 ***" << endl;
    } while (scoreThree < 0 || scoreThree > 100);
    cout << endl;
    math.setScoreThree(scoreThree);
    
    
    // displays the test scores and the average
    cout << setprecision(1) << fixed;
    cout << "SCORES SUMMARY" << endl;
    cout << "Score One:  " << math.getScoreOne() << endl;
    cout << "Score Two:  " << math.getScoreTwo() << endl;
    cout << "Score Three:  " << math.getScoreThree() << endl;
    cout << "Average:  " << math.getScoresAverage() << endl;
    cout << endl;
    
    // exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

