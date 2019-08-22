/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 12 Challenge 5
 *  Line Numbers: Write a program that asks the user for the name of a file. The 
 *  program should display the contents of the file on the screen. Each line of 
 *  screen output should be preceded with a line number, following by a colon. 
 *  The line number should start at 1. Here is an example:
 *      1: Goerge Rolland
 *      2: 127 Academy Street
 *      3: Brasstown, NC 28706
 * 
 *  If the file's contents won't fit on a single screen, the program should 
 *  display 24 lines of output at a time, and then pause. Each time the program 
 *  pauses, it should wait for the user to strike a key before the next 24 lines 
 *  are displayed.
 */

# include <iostream>
# include <fstream>
# include <string>
using namespace std;


// Function prototypes
string getUserFile();
void processFile(string);
void showLines(fstream&);

int main()
{
    // Variables
    string userFile;
    char terminator;
    
    // Welcome message
    cout << "This program will display the contents of text files." << endl;
    cout << "If the file is long, 24 lines will be displayed at a time." << endl;
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
    
    cout << "This directory contains the following files you can open:" << endl;
    cout << "\tnfl_teams.txt" << endl;
    cout << "\tafc_teams.txt" << endl;
    cout << "\tnfc_teams.txt" << endl;
    cout << endl;
    cout << "Enter the file you want read:  ";
    getline(cin, userFile);
    cout << endl;
    
    return userFile;
}

// processFile opens a file, checking for failure, then calls showLines to 
// display each line, 24 lines at a time if necessary
void processFile(string fileName)
{
    fstream dataFile;
    
    dataFile.open(fileName);
    if (dataFile.fail())
    {
        cout << "That file does not exist. Check spelling, and makes sure to include the file extension." << endl;
        cout << endl;
    }
    else
    {
        cout << "Showing contents of " << fileName <<  " file.............." << endl;
        showLines(dataFile);
        cout << endl;
    }
    dataFile.close();
}

void showLines(fstream &file)
{
    int lineCounter = 1;
    string line;
    
    getline(file, line, '\n');
    while(file)
    {
        cout << lineCounter << ": " << line << endl;
        if (lineCounter % 24 == 0)
        {
            cout << endl;
            cout << "Press [Enter] to continue reading file." << endl;
            cin.get();
            cout << endl;
        }
        getline(file, line, '\n');
        lineCounter += 1;
    }
}