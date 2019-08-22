/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 5 Challenge 8
 *  Math Tutor: 
 *  This challenge started in Challenge 17 of Chapter 3:
 *  Write a program that can be used as a math tutor for a young student. The 
 *  program should display two random numbers to be added, such as
 *   247
 *  +129
 *  ----
 * 
 *  The program should then pause while the student works on the problem. When 
 *  the student is ready to check the answer, he or she can press a key and the 
 *  program will display the correct solution:
 *   247
 *  +129
 *  ----
 *   376
 * 
 * And was modified in the Programming Challenge 11 of Chapter 4:
 * Write a program that can be used as a math tutor for a young student. The 
 * program should display two random numbers that are to be added, such as:
 *  247
 * +129
 * ----
 * 
 * The program should wait for the student to enter the answer. If the answer is 
 * correct, a message of congratulations should be printed. If the answer is 
 * incorrect, a message should be printed showing the correct answer.
 * 
 * Modify the program again so it displays a menu allowing the user to select 
 * an addition, subtraction, multiplication, or division problem. The final 
 * selection on the menu should let the user quit the program. After the user 
 * has finished the math problem, the program should display the menu again. 
 * This process is repeated until the user chooses to quit the program.
 * 
 * Input Validation: If the user selects an item not on the menu, display an 
 * error message and display the menu again.
 */

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <ctime>
using namespace std;

int main() 
{
    // Constants for range of random numbers and menu items
    const int   ADDITION_CHOICE = 1,
                SUBTRACTION_CHOICE = 2,
                MULTIPLICATION_CHOICE = 3,
                DIVISION_CHOICE = 4,
                QUIT_CHOICE = 5;            
    
    // Variables for random numbers
    int menu_choice, 
        min_random_number, 
        max_random_number, 
        number_1, 
        number_2, 
        correct_answer, 
        user_answer;
    
    unsigned seed = time(0); // Time variable for seeding random number generator
    srand(seed); // Uses time to see the random number generator
    
    do
    {
        // Display the menu
        cout    << "\nTry A Math Problem:\n"
                << "1. Addition\n"
                << "2. Subtraction\n"
                << "3. Multiplication\n"
                << "4. Division\n"
                << "5. Quit the Program\n\n"
                << "Enter your choice: ";
        
        cin >> menu_choice;
        // cin.ignore statement prevents infinite loop if user enters float
        cin.ignore(20, '\n');
        
        while(menu_choice < 1 || menu_choice > 5)
        {
            cout << "\nPlease enter a valid menu choice: ";
            cin >> menu_choice;
        }
        
        if (menu_choice != QUIT_CHOICE)
        {
            switch (menu_choice)
            {
                case ADDITION_CHOICE:
                    // Set min and max random numbers
                    min_random_number = 100;
                    max_random_number = 999;
                    
                    // Generate random numbers
                    number_1 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    number_2 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    
                    // Calculate correct answer
                    correct_answer = number_1 + number_2;                    
                    
                    // Display problem
                    cout << "\n";
                    cout << left << setw(2) << ' ';
                    cout << right << setw(4) << number_1 << endl;
                    cout << left << setw(2) << '+';
                    cout << right << setw(4) << number_2 << endl;
                    cout << "------" << endl;
                    cout << "\n\nEnter your answer:";
                    
                    // Get answer from user
                    cin >> user_answer;
                    // cin.ignore statement prevents infinite loop if user enters float
                    cin.ignore(20, '\n');
                    // Check if the user's answer is correct
                    if(user_answer == correct_answer)
                    {
                        cout << "\nGood job! That is the correct answer." << endl;        
                    }
                    else
                    {
                        cout << "\nNot correct. See solution below:\n" << endl;
                        cout << left << setw(2) << ' ';
                        cout << right << setw(4) << number_1 << endl;
                        cout << left << setw(2) << '+';
                        cout << right << setw(4) << number_2 << endl;
                        cout << "------" << endl;
                        cout << left << setw(2) << ' ';
                        cout << right << setw(4) << correct_answer << endl;
                    }
                    break;
                
                case SUBTRACTION_CHOICE:
                    // Set min and max random numbers
                    min_random_number = 100;
                    max_random_number = 999;
                    
                    // Generate random numbers
                    number_1 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    number_2 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    
                    // Calculate correct answer
                    correct_answer = number_1 - number_2;                    
                    
                    // Display problem
                    cout << "\n";
                    cout << left << setw(2) << ' ';
                    cout << right << setw(4) << number_1 << endl;
                    cout << left << setw(2) << '-';
                    cout << right << setw(4) << number_2 << endl;
                    cout << "------" << endl;
                    cout << "\n\nEnter your answer:" << endl;
                    
                    // Get answer from user
                    cin >> user_answer;
                    // cin.ignore statement prevents infinite loop if user enters float
                    cin.ignore(20, '\n');
                    // Check if the user's answer is correct
                    if(user_answer == correct_answer)
                    {
                        cout << "\nGood job! That is the correct answer." << endl;        
                    }
                    else
                    {
                        cout << "\nNot correct. See solution below:\n" << endl;
                        cout << left << setw(2) << ' ';
                        cout << right << setw(4) << number_1 << endl;
                        cout << left << setw(2) << '-';
                        cout << right << setw(4) << number_2 << endl;
                        cout << "------" << endl;
                        cout << left << setw(2) << ' ';
                        cout << right << setw(4) << correct_answer << endl;
                    }
                    break;
                    
                case MULTIPLICATION_CHOICE:
                    // Set min and max random numbers
                    min_random_number = 10;
                    max_random_number = 99;
                    
                    // Generate random numbers
                    number_1 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    number_2 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    
                    // Calculate correct answer
                    correct_answer = number_1 * number_2;
                    
                    // Display problem
                    cout << "\n";
                    cout << number_1 << " * " << number_2 << " = " << endl;
                    cout << "\n\nEnter your answer:" << endl;
                    
                    // Get answer from user
                    cin >> user_answer;
                    // cin.ignore statement prevents infinite loop if user enters float
                    cin.ignore(20, '\n');
                    // Check if the user's answer is correct
                    if(user_answer == correct_answer)
                    {
                        cout << "\nGood job! That is the correct answer." << endl;        
                    }
                    else
                    {
                        cout << "\nNot correct. See solution below:\n" << endl;
                        cout << number_1 << " * " << number_2 << " = " << correct_answer << endl;
                    }
                    break;
                    
                case DIVISION_CHOICE:
                    // Set min and max random numbers
                    min_random_number = 10;
                    max_random_number = 999;
                    
                    // do-while loop ensures the correct answer is an int
                    do 
                    {
                        // Generate random numbers                    
                        number_1 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                        number_2 = (rand() % (max_random_number - min_random_number + 1)) + min_random_number;
                    } while(number_1 % number_2 != 0);
                    
                    // Calculate correct answer
                    correct_answer = number_1 / number_2;
                    
                    // Display problem
                    cout << "\n";
                    cout << number_1 << " / " << number_2 << " = " << endl;
                    cout << "\n\nEnter your answer (Hint: the correct answer is a whole number):" << endl;
                    
                    // Get answer from user
                    cin >> user_answer;
                    // cin.ignore statement prevents infinite loop if user enters float
                    cin.ignore(20, '\n');
                    // Check if the user's answer is correct
                    if(user_answer == correct_answer)
                    {
                        cout << "\nGood job! That is the correct answer." << endl;        
                    }
                    else
                    {
                        cout << "\nNot correct. See solution below:\n" << endl;
                        cout << number_1 << " / " << number_2 << " = " << correct_answer << endl;
                    }
                    break;
            }
        }
        
    } while(menu_choice != QUIT_CHOICE);
    
    cout << "\n\nPress the [Enter] key to exit this program.\n" << endl;
    cin.get();    
    return 0;
}