/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 12 Challenge 7
 *  Sentence Filter: Write a program that asks the user for two file names. The 
 *  first file will be opened for input, and the second file will be opened for 
 *  output. (It will be assumed the first file contains sentences that end with 
 *  a period.) The program will read the contents of the first file and change 
 *  all the letters to lowercase except the first letter of each sentence, which 
 *  should be made uppercase. The revised contents should be stored in the 
 *  second file.
 */

# include <iostream>
# include <fstream>
# include <string>
using namespace std;


// Function prototypes
string getUserFile();
void processFiles(string, string);
void showContents(fstream&);

int main()
{
    // Variables
    string userInputFile;
    string userOutputFile;
    char terminator;
    
    // Welcome message
    cout << "This program filters a text file, outputting the contents to another file." << endl;
    cout << endl;
    
    // loop to continuously prompt user for input and output files
    do
    {
        userInputFile = getUserFile();
        cout << "Enter a name for your output file:  ";
        getline(cin, userOutputFile);
        cout << endl;
        processFiles(userInputFile, userOutputFile);
        cout << "Would you like to filter another file (Y/N)?  ";
        cin >> terminator;
        cin.ignore(256, '\n');
        cout << endl;
        
    } while (terminator == 'Y' || terminator == 'y');
    
    // Exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();
}

// getUserFile lists the available files for the user (hardcoded filenames)
// then prompts the user to enter one of the available files
string getUserFile()
{
    string userInputFile;
    
    
    cout << "The following files are available for input:" << endl;
    cout << "\tlinux_scripting_intro.txt" << endl;
    cout << "\toperating_system.txt" << endl;
    cout << "\tjoke.txt" << endl;
    cout << endl;
    cout << "Enter the name of the file you want to filter:  ";
    getline(cin, userInputFile);
    cout << endl;
    
    return userInputFile;
}

// processFiles opens two files based on the name arguments, checking for failure. 
// It then performs the toupper and tolower filtering of the relevant chars.
// Lastly, processFiles displays the contents of both the input and output files.
void processFiles(string userInputFile, string userOutputFile)
{
    fstream inputFile;
    fstream outputFile;
    char ch;
    
    inputFile.open(userInputFile, ios::in);
    outputFile.open(userOutputFile, ios::out);
    
    // checks if file failed to open, displaying an error message if it failed
    if (inputFile.fail())
    {
        cout << "The input file you specified does not exist." << endl; 
        cout << "Check spelling, and makes sure to include the file extension." << endl;
        cout << endl;
    }
    else
    {
        // gets the first char from input and puts that char to output in uppercase
        inputFile.get(ch);
        outputFile.put(toupper(ch));
        
        // gets the next char, then loops through the remaining chars
        inputFile.get(ch);
        while(inputFile)
        {
            // if statement to handle the uppercase chars after '.'
            if (ch == '.')
            {
                outputFile.put(ch);
                inputFile.get(ch);
                if(inputFile)
                {
                    if (ch == ' ' || ch == '\n')
                {
                    outputFile.put(ch);
                    inputFile.get(ch);
                    outputFile.put(toupper(ch));
                }
                else
                {
                    outputFile.put(toupper(ch));
                }
                }
            }
            else
            {
                outputFile.put(tolower(ch));
            }
            // get the next char for the while loop to check
            inputFile.get(ch);
        }
        inputFile.close();
        outputFile.close();
        
        // contents of both input and output files are reopened and displayed
        inputFile.open(userInputFile, ios::in);
        cout << "Showing contents of " << userInputFile <<  " file.............." << endl;
        showContents(inputFile);
        cout << endl;
        
        outputFile.open(userOutputFile, ios::in);
        cout << "Showing contents of " << userOutputFile <<  " file.............." << endl;
        showContents(outputFile);
        cout << endl;
    }
    inputFile.close();
    outputFile.close();
}

// showContents function displays all contents of a text file, line by line
void showContents(fstream &file)
{
    string line;
    
    getline(file, line, '\n');
    while (file)
    {
        cout << line << endl;
        getline(file, line, '\n');
    }
}

