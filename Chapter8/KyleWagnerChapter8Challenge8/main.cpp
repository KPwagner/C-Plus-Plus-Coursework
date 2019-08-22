/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 8 Challenge 8
 *  Search Benchmarks: Write a program that has an array of at least 20 
 *  integers. It should call a function that uses the linear search algorithm to 
 *  locate one of the values. The function should keep a count of the number of 
 *  comparisons it makes until it finds the value. The program then should call 
 *  a function that uses the binary search algorithm to locate the same value. 
 *  It should also keep count of the number of comparisons it makes. Display 
 *  these values on the screen.
 */

# include <iostream>
# include <iomanip>
using namespace std;

// Function prototypes
void showNumbers(const int[], int, int);
void testNumber(const int[], int, int);
int benchmarkBinary(const int[], int, int);
int benchmarkLinear(const int[], int, int);

int main()
{
    // Variables
    const int SIZE = 40;
    int search_number;
    // These numbers must be in sorted order for the binary search algorithm
    int numbers[SIZE] = {
        12345, 12456, 13579, 21564, 24564, 25678, 26678, 26791, 26792, 33445, 
        34565, 35645, 36794, 37645, 38465, 39112, 41366, 43654, 45134, 48954,
        49785, 51456, 54134, 55555, 57456, 59764, 61435, 62483, 64356, 65453, 
        68345, 71456, 75645, 77777, 79422, 82456, 85647, 87894, 91456, 93121
    };
    
    // Welcome message
    cout << "This program benchmarks linear and binary search algorithms." << endl;
    cout << "Here is the array of numbers used for searching:" << endl;
    showNumbers(numbers, SIZE, 10);
    
    // User prompt
    cout << "Enter a search number:" << endl;
    cin >> search_number;
    cin.ignore(20, '\n'); // Prevents problems on non-int user input
    
    testNumber(numbers, SIZE, search_number);
    
    cout << "Press [ENTER] to exit program" << endl;
    cin.get();
    return 0;
}


void showNumbers(const int numbers[], int size, int cols)
{
    // Displays the numbers array in an easy to read table
    cout << endl;
    for (int num = 1; num <= size; num++)
    {
        cout << setw(9) << right << numbers[num - 1];
        if (num % cols == 0)
            cout << endl;
    }
    cout << endl;
}

int benchmarkBinary(const int numbers[], int size, int search_number)
{   
    // Uses the binary search algorithm; outputs number of comparisons
    // or -1 if if search value not found
    
    // Variables
    int first = 0,
        last = size -1,
        middle,
        comparisons = 0;
      
    // Binary search returns number of comparisons if winning number is found
    while (first <= last)
    {
        middle = (first + last) / 2;
        comparisons += 1;
        if (numbers[middle] == search_number)
        {
            return comparisons; // Search number found
        }
        else if (numbers[middle] > search_number)
            last = middle -1;
        else
            first = middle + 1;
    }
    return -1; // Search number not found
}

int benchmarkLinear(const int numbers[], int size, int search_number)
{
    // Uses the linear search algorithm; outputs number of comparisons
    // or -1 if if search value not found
    
    int index = 0; // Used as subscript to search the array
    
    // Linear search returns number of comparisons if the number is found
    while (index < size)
    {
        if(numbers[index] == search_number) // Search number found
        {
            return index + 1; // Returns the number of comparisons
        }
        index++;
    }
    return -1;   // Search number was not found
}

void testNumber(const int numbers[], int size, int search_number)
{
    // Displays the results (number of comparisons) of searching 
    // for a given search number
    
    int linear_comparisons, binary_comparisons;
    
    cout << endl;
    cout << "Searching for " << search_number << ".........." << endl;
    linear_comparisons = benchmarkLinear(numbers, size, search_number);
    binary_comparisons = benchmarkBinary(numbers, size, search_number);
    if (linear_comparisons != -1 && binary_comparisons != -1)
    {
        cout << search_number << " was found by both linear and binary algorithms." << endl;
        cout << "Number of comparisons required by each algorithm:" << endl;
        cout << "LINEAR: " << linear_comparisons << endl;
        cout << "BINARY: " << binary_comparisons << endl;
    }
    else
    {
        cout << "At least one of the search algorithms failed to find " << search_number << endl;
    }
    cout << endl;
}