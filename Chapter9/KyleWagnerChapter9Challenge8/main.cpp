/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 9 Challenge 8
 *  Mode Function: In statistics, the mode of a set of values is the value that 
 *  occurs most often or with the greatest frequency. Write a function that 
 *  accepts as arguments the following:
 *  (A) An array of integers
 *  (B) An integer that indicates the number of elements in the array
 *  
 *  The function should determine the mode of the array. That is, it should 
 *  determine which value in the array occurs most often. The mode is the value 
 *  the function should return. If the array has no mode (non of the values 
 *  occur more than once), the function should return -1.
 * (Assume the array will always contain nonnegative values.)
 * 
 *  Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// Function prototypes
void sortArray(int[], int);
void showArray(int[], int);
int getMode(int[], int);

int main()
{
    int mode;
    const int SIZE_1 = 30;
    int numbers_1[SIZE_1] = {1,13,15,15,23,6,6,1,2,2,4,6,4,5,6,7,8,7,6,5,4,3,8,9,9,8,12,6,12,6};
    const int SIZE_2 = 9;
    int numbers_2[SIZE_2] = {9,8,7,6,5,4,3,2,1};
    
    // Welcome message
    cout << "This program uses a function to determine the mode of an array of integers." << endl;
    
    // Test #1
    cout << "\n================================================" << endl;
    cout << "Testing array number one......................" << endl;
    cout << "Test array one values are:" << endl;
    showArray(numbers_1, SIZE_1);
    cout << "Sorted in ascending order, the numbers are:" << endl;
    sortArray(numbers_1, SIZE_1);
    showArray(numbers_1, SIZE_1);
    mode = getMode(numbers_1, SIZE_1);
    cout << "Mode is " << mode << endl;
    
    // Test #2
    cout << "\n================================================" << endl;
    cout << "Testing array number two......................" << endl;
    cout << "Test array two values are:" << endl;
    showArray(numbers_2, SIZE_2);
    cout << "Sorted in ascending order, the numbers are:" << endl;
    sortArray(numbers_2, SIZE_2);
    showArray(numbers_2, SIZE_2);
    mode = getMode(numbers_2, SIZE_2);
    cout << "Mode is " << mode << endl;
    
    cout << "\nPress [Enter] to exit program." << endl;
    
    cin.get();
    return 0;
}

void showArray(int numbers[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << *(numbers + index) << " ";
    }
    cout << endl;
}

void sortArray(int numbers[], int size)
{
    int maxElement;
    int index;
    
    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (*(numbers + index) > *(numbers + index + 1))
            {
                swap(*(numbers + index), *(numbers + index + 1));
            }
        }
    }
}

int getMode(int numbers[], int size)
{
    int mode_number = -1;
    int current_number = -1;
    int previous_number;
    int mode_count = 1;
    int current_count = 1;
    for (int index = 0; index < size; index++)
    {
        current_number = *(numbers + index);
        previous_number = *(numbers + index -1);
        if(current_number == previous_number)
        {   
            current_count += 1;
        }
        else
        {            
            current_count = 1;
        }
        if(current_count > mode_count)
        {
            mode_number = current_number;
            mode_count = current_count;
        }
    }
    return mode_number;
}
