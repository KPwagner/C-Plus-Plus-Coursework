/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 7 Challenge 4
 *  Larger than n: In a program, write a function that accepts three arguments: 
 *  an array, the size of the array, and a number n. Assume the array contains 
 *  integers. The function should display all of the numbers in the array that 
 *  are greater than the number n.
 */

# include <iostream>
using namespace std;

void greaterThan(int [], int, int);
void showValues(int [], int);

int main()
{
    const int   ARRAY_SIZE = 8,
                TEST_NUMBER_1 = -3,
                TEST_NUMBER_2 = 7,
                TEST_NUMBER_3 = 21;
    
    int numbers_array[ARRAY_SIZE] = {-10,-5,0,5,10,15,23,101};
    
    // Perform test #1
    cout << "=======================" << endl;
    cout << "Performing a test......" << endl;
    cout << "Calling function greaterThan with arguments ";
    showValues(numbers_array, ARRAY_SIZE);
    cout << ", " << ARRAY_SIZE << ", and " << TEST_NUMBER_1 << endl;
    greaterThan(numbers_array, ARRAY_SIZE, TEST_NUMBER_1);

    // Perform test #2
    cout << "\n\n=======================" << endl;
    cout << "Performing a test......" << endl;
    cout << "Calling function greaterThan with arguments ";
    showValues(numbers_array, ARRAY_SIZE);
    cout << ", " << ARRAY_SIZE << ", and " << TEST_NUMBER_2 << endl;
    greaterThan(numbers_array, ARRAY_SIZE, TEST_NUMBER_2);
    
    // Perform test #3
    cout << "\n\n=======================" << endl;
    cout << "Performing a test......" << endl;
    cout << "Calling function greaterThan with arguments ";
    showValues(numbers_array, ARRAY_SIZE);
    cout << ", " << ARRAY_SIZE << ", and " << TEST_NUMBER_3 << endl;
    greaterThan(numbers_array, ARRAY_SIZE, TEST_NUMBER_3);
    
    cin.get();
}

void greaterThan(int numbers_array[], int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (numbers_array[i] > number)
            cout << numbers_array[i] << " is greater than " << number << '.' << endl;
    }
}

void showValues(int numbers_array[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers_array[i] << " ";
    }
    cout << "]";
}