/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 9 Challenge 4
 *  Test Scores #2: Modify the program of Programming Challenge 2 
 *  (Test Scores #1, see below) to allow the user to enter name-score pairs. 
 *  For each student taking a test, the user types the student's name followed 
 *  by the student's integer test score. Modify the sorting function so it takes 
 *  an array holding the student names, and an array holding the student test 
 *  scores. When the sorted list of scores is displayed, each student's name 
 *  should be displayed along with his or her score. In stepping through the 
 *  arrays, user pointers rather than array subscripts.
 *  
 *  Test Scores #1: Write a program that dynamically allocates an array large 
 *  enough to hold a user-defined number of test scores. Once all the scores are 
 *  entered, the array should be passed to a function that sorts them in 
 *  ascending order. Another function should be called that calculates the 
 *  average score. The program should display the sorted list of scores and 
 *  averages with appropriate headings. Use pointer notation rather than array 
 *  notation whenever possible.
 *  Input Validation: Do not accept negative numbers for test scores.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// Function prototypes
int *getScoresArray(int);
string *getNamesArray(int);
void showScores(string[], int[], int);
void sortArrays(string[], int[], int);
void swap(int &, int &);
double getAverage(int[], int);

int main()
{
    int size;
    string *names = nullptr;    // Pointer for the array
    int *scores = nullptr;      // Pointer for the array
    double average_score;
 
    // Welcome message
    cout << "This program dynamically allocates student names and test scores" << endl;
    cout << "to an array of integers." << endl;
    cout << "Array values are initialized to -1 and '_'." << endl;
    // Prompt user for size of array
    cout << "\nHow many students will you enter scores for?" << endl;
    cin >> size;
    cin.ignore(20, '\n');   // Prevent problems when non-int values entered
    
    names = getNamesArray(size);
    scores = getScoresArray(size);
    
    for (int index = 0; index < size; index++)
    {
        string name;
        int score;
        do
        {
            cout << "\nEnter the name (no spaces) and test score, separated by a space, for a student:" << endl;
            cin >> name >> score;
            cin.ignore(20, '\n');   // Prevent problems when non-int values entered
            if (score <= 0)
                cout << "Error: negative scores are not allowed. Try again." << endl;
        } while(score <= 0);
        
        *(names + index) = name;
        *(scores + index) = score;
    }
        
    
    average_score = getAverage(scores, size);
    sortArrays(names, scores, size);
    
    cout << "\nThe average score is " << setprecision(1) << fixed << average_score << endl;
    showScores(names, scores, size);
    
    cout << "\nPress [Enter] to free memory and exit." << endl;
    cin.get();
    
    // Free the memory
    delete [] scores;
    names = nullptr;
    scores = nullptr;   
    return 0;
}

/*
 * getArray returns a pointer to an array with size 
 * dictated by the parameter; getArray also prompts user to populate the array.
 *  Array is initalized with int values -1.
 */
int *getScoresArray(int size)
{
    int *arr = nullptr;     // Declare array pointer
    
    // Return a null pointer if num is zero or negative
    if (size <= 0)
        return nullptr;
    
    // Dynamically allocate the array
    arr = new int[size];
    
    // Values initialized to -1 so it's obvious which values are unmodified when
    // the array is displayed
    for (int count = 0; count < size; count++)
        arr[count] = -1;
    
    // Return pointer to the array
    return arr;
}

string *getNamesArray(int size)
{
    string *arr = nullptr;     // Declare array pointer
    
    // Return a null pointer if num is zero or negative
    if (size <= 0)
        return nullptr;
    
    // Dynamically allocate the array
    arr = new string[size];
    
    // Values initialized to _ so it's obvious which values are unmodified when
    // the array is displayed
    for (int count = 0; count < size; count++)
        arr[count] = "_";
    
    // Return pointer to the array
    return arr;
}

void showScores(string names[], int scores[], int size)
{
    cout << "\nHere is a list of all the names and scores." << endl;
    cout << "(ascending order by score from top to bottom)" << endl;
    for (int index = 0; index < size; index++)
    {
        cout << setfill('_');
        cout << setw(24) << left << *(names + index) << setw(3) << right << *(scores + index) << endl;
    }
}

// sortArray function sort an array using bubble sort algorithm
void sortArrays(string names[], int scores[], int size)
{
    int maxElement;
    int index;
    
    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (*(scores + index) > *(scores + index + 1))
            {
                swap(*(names + index), *(names + index + 1));
                swap(*(scores + index), *(scores + index + 1));
            }
        }
    }
}

// swap function simultaneously switches two values. Required in sortArray function.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// getAverage function calculates the average of all values in an array.
double getAverage(int arr[], int size)
{
    double total, average;
    for (int index = 0; index < size; index++)
    {
        total += *(arr + index);
    }
    average = total / size;
    return average;
}