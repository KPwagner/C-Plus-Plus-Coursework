/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 12 Challenge 1
 *  File Head Program: Write a program that asks the user for the name of a 
 *  file. The program should display the first ten lines of the file on the 
 *  screen (the "head" of the file). If the file has fewer than ten lines, the 
 *  entire file should be displayed, with a message indicating the entire file 
 *  has been displayed.
 */

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

// Function prototypes
void showContents(ifstream&);
void showHead(ifstream&);
string getUserFile();
void processFile(string);

int main()
{    
    // Variables
    string userFile;
    char terminator;
    
    // Welcome message
    cout << "This program will display the head (first ten lines) of text files." << endl;
    cout << endl;
    
    // Prompts user for file name, and process the file with display functions
    // Continues to prompt user as long as they want
    do
    {
        userFile = getUserFile();
        processFile(userFile);
        cout << "Would you like to read another file (Y/N)?  ";
        cin >> terminator;
        cin.ignore(256, '\n');
        cout << endl;
        
    } while (terminator == 'Y' || terminator == 'y');
    
    // Exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
    return 0;
}

// getUserFile lists the available files for the user (hardcoded filenames)
// then prompts the user to enter one of the available files
string getUserFile()
{
    string userFile;
    
    cout << "This directory contains two files you can open:" << endl;
    cout << "\tnfl_teams.txt" << endl;
    cout << "\tAFC_west_teams.txt" << endl;
    cout << endl;
    cout << "Enter the file you want read:  ";
    getline(cin, userFile);
    cout << endl;
    
    return userFile;
}

// processFile opens a file, checking for failure, then calls showHead to display
// head (first ten lines) content
void processFile(string fileName)
{
    ifstream dataFile;
    
    dataFile.open(fileName);
    if (dataFile.fail())
    {
        cout << "That file does not exist. Check spelling, and makes sure to include the file extension." << endl;
        cout << endl;
    }
    else
    {
        cout << "Showing head of " << fileName <<  " file.............." << endl;
        showHead(dataFile);
        cout << endl;
    }
    dataFile.close();
}

// showHead function displays the first ten lines of a text file
void showHead(ifstream &file)
{
    int headLength = 10;
    string line;
    
    for (int count = 1; count <= headLength; count++)
    {
        if (file.eof())
        {          
            cout << "\nThe entire file has been displayed." << endl;
            break;
        }
        else
        {
            getline(file, line, '\n');
            cout << line << endl;
        }
    }
}

// showContents function displays all contents of a text file, line by line
void showContents(ifstream &file)
{
    string line;
    
    while (file >> line)
    {
        cout << line << endl;
    }
}