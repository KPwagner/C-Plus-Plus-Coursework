/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 9 Challenge 1
 *  Array Allocator: Write a function that dynamically allocates an array of 
 *  integers. The function should accept an integer argument indicating the 
 *  number of elements to allocate. The function should return a pointer to the 
 *  array.
 */

# include <iostream>
using namespace std;

// Function prototypes
int *getArray(int);

int main()
{
    int size;
    int *numbers = nullptr;     // Pointer for the array
 
    // Welcome message
    cout << "This program dynamically allocates an array of integers." << endl;
    // Prompt user for size of array
    cout << "\nEnter a non-negative integer for the size of the array:" << endl;
    cin >> size;
    
    numbers = getArray(size);      // Initializes numbers variable with array.
    
    cout << "\nSuccess." << endl;
    cout << "Memory Address: " << numbers << endl;
    
    cout << "\nPress [Enter] to free memory and exit." << endl;
    cin.ignore(20, '\n');
    cin.get();
    
    // Free the memory
    delete [] numbers;
    numbers = nullptr;    
    return 0;
}

/*
 * The getArray function returns a pointer to an array with size 
 * dictated by the parameter.
 */

int *getArray(int num)
{
    int *arr = nullptr;     // Declare array pointer
    
    // Return a null pointer if num is zero or negative
    if (num <= 0)
        return nullptr;
    
    // Dynamically allocate the array
    arr = new int[num];
    
    // Return pointer to the array
    return arr;
}