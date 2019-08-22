/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 12 Challenge 3
 *  Punch Line: Write a program that reads and prints a joke and its punch line 
 *  from two different files. The first file contains a joke, but not its punch 
 *  line. The second file has the punch line as its last line, preceded by 
 *  "garbage". The main function of your program should open the two files then 
 *  call two functions, passing each one the file it needs. The first function 
 *  should read and display each line in the file it is passed (the joke file). 
 *  The second function should display only the last line of the file it is 
 *  passed (the punch line file). It should find this line by seeking to the end 
 *  of file and then backing up to the beginning of the last line.
 */

# include <iostream>
# include <fstream>
# include <string>
using namespace std;


// Function prototypes
void readForward(fstream&);
void readLastLine(fstream&);


int main()
{
    fstream jokeFile;
    fstream punchlineFile;
    
    // Welcome message
    cout << "This program displays a joke and punchline from two different files." << endl;
    cout << endl;
    
    // Opens files
    jokeFile.open("joke.txt");
    punchlineFile.open("punchline.txt");
    
    // Reads files
    readForward(jokeFile);
    readLastLine(punchlineFile);
    
    // Closes files
    jokeFile.close();
    punchlineFile.close();    
    
    // Exit message
    cout << "Press [Enter] to exit program." << endl;
    cin.get();    
}

// readForward function reads and fstream file char by char from beginning to end
void readForward(fstream &file)
{
    char ch;
    
    cout << "JOKE:" << endl;
    while(file)
    {
        cout << ch;
        file.get(ch);
    }
    cout << endl;
    cout << endl;
}

// readLastLine function locates the last line of an fstream file, 
// then displays that line
void readLastLine(fstream &file)
{
    char ch;
    int offset;
    string line;
    
    cout << "PUNCHLINE:" << endl;
    
    // sets position to end of the file
    file.seekg(ios::end);
    
    offset = -1;
    
    while(file)
    {
        // sets position to second from end and gets the char at position
        file.seekg(offset, ios::end);
        file.get(ch);
        
        // if and while work backwards to search for the '\n' char from end of file
        if (ch == '\n')
        {
            // gets and reads line
            getline(file, line, '\n');
            cout << line << endl;
            cout << endl;
            break;
        }
        else
        {
            // moves position back one char
            offset -= 1;
        }
    }
    
    cout << endl;
}