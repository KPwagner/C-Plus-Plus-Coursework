/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 7 Challenge 8
 *  Lo Shu Magic Square: The Lo Shu Magic Square is a grid with 3 rows and 
 *  3 columns. The Lo Shu Magic Square has the following properties:
 *  > The grid contains the numbers 1 through 9 exactly.
 *  > The sum of each row, each column, and each diagonal all add up to the same 
 *  number.
 *  
 *  In a program, you can simulate a magic square using a two-dimensional array. 
 *  Write a function that accepts a two-dimensional array as an argument, and 
 *  determines whether the array is a Lo Shu Magic Square. Test the function in 
 *  a program.
 */

# include <iostream>
# include <iomanip>
using namespace std;

const int COLS = 3;
const int ROWS = 3;

void showValues(const int [][COLS], int);
void showSums(const int [][COLS], int);
void testTable(const int [][COLS], int);
bool isLoShu(const int numbers[][COLS], int);


int main()
{
    int table_1[ROWS][COLS] =  {{4,9,2},
                                {3,5,7},
                                {8,1,6}};
    
    int table_2[ROWS][COLS] =  {{1,1,1},
                                {1,2,2},
                                {1,2,3}};
    
    int table_3[ROWS][COLS] =  {{1,2,3},
                                {2,2,3},
                                {3,3,3}};
    
    int table_4[ROWS][COLS] =  {{1,1,2},
                                {1,2,1},
                                {2,1,1}};
    
    int table_5[ROWS][COLS] =  {{9,9,9},
                                {9,9,9},
                                {9,9,9}};
    
    
    testTable(table_1, ROWS);
    testTable(table_2, ROWS);
    testTable(table_3, ROWS);
    testTable(table_4, ROWS);
    testTable(table_5, ROWS);
    
    cin.get();
}

void showValues(const int numbers[][COLS], int rows)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << setw(2) << numbers[row][col];
        }
        cout << endl;
    }
}

void showSums(const int numbers[][COLS], int rows)
{
    int row_sum, col_sum, diagonal_one_sum, diagonal_two_sum;
    
    diagonal_one_sum = 0;   // Top left to bottom right
    diagonal_two_sum = 0;   // Bottom left to top right
    
    for (int row = 0; row < rows; row++)
    {
        row_sum = 0;
        col_sum = 0;
        diagonal_one_sum += numbers[row][row];
        diagonal_two_sum += numbers[row][2- row];
        
        for (int col = 0; col < COLS; col++)
        {
            row_sum += numbers[row][col];
            col_sum += numbers[col][row];            
        }
        cout << "Row " << row << ": " << row_sum << endl;
        cout << "Col " << row << ": " << col_sum << endl;                
    }
    cout << "Diagonal TL to BR: " << diagonal_one_sum << endl;
    cout << "Diagonal BL to TR: " << diagonal_two_sum << endl;
}

bool isLoShu(const int numbers[][COLS], int rows)
{
    bool result;
    int row_sum, col_sum, diagonal_one_sum, diagonal_two_sum, base_sum;
    
    // Create sum of top row to compare all others against
    base_sum = numbers[0][0] + numbers[0][1] + numbers[0][2];
    
    diagonal_one_sum = 0;   // Top left to bottom right
    diagonal_two_sum = 0;   // Bottom left to top right
    
    for (int row = 0; row < rows; row++)
    {
        row_sum = 0;
        col_sum = 0;
        diagonal_one_sum += numbers[row][row];
        diagonal_two_sum += numbers[row][2- row];
        
        for (int col = 0; col < COLS; col++)
        {
            row_sum += numbers[row][col];
            col_sum += numbers[col][row];            
        }
        if (row_sum != base_sum || col_sum != base_sum)
            return false;
    }
    if (diagonal_one_sum != base_sum || diagonal_two_sum != base_sum)
        return false;
   
    return true;
}

void testTable(const int numbers[][COLS], int rows)
{
    cout << "=================================" << endl;
    cout << "Testing the following table......" << endl;
    showValues(numbers, rows);
    cout << "\nThis table has the following sums:" << endl;
    showSums(numbers, rows);
    if (isLoShu(numbers, rows))
    {
        cout << "\nThis table is a LoShu Magic Square.\n\n" << endl;
    }
    else
    {
        cout << "\nThis table is not a LoShu Magic Square.\n\n" << endl;
    } 
}