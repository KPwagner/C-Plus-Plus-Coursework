/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 11 Challenge 1
 *  Movie Data: Write a program that uses a structure named MovieData to store 
 *  the following information about a movie:
 *      Title
 *      Director
 *      Year Released
 *      Running Time (in minutes)
 * 
 *  The program should create two MovieData variables, store values in their 
 *  members, and pass each one, in turn, to a function that displays the 
 *  information about the movie in a clearly formatted manner.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

struct MovieData
{
    string title;
    string director;
    int releaseYear;
    int runningTime;
};

void showMovie(MovieData);  // Function prototype

int main()
{
    // MovieData variables
    MovieData goodfellas = {"Goodfellas", "Martin Scorsese", 1990, 146};
    MovieData casino = {"Casino", "Martin Scorsese", 1995, 178};
    
    // Welcome message
    cout << "This program stores movie data in structures, and displays the data "; 
    cout << "with a function named showMovie." << endl;
    
    // Function calls to display MovieData content
    showMovie(goodfellas);
    showMovie(casino);
    
    // Exit message
    cout << endl;
    cout << "Press [Enter] to exit this program." << endl;
    cin.get();
}

void showMovie(MovieData movie)
{
    cout << endl;
    cout << "Calling showMovie function......................" << endl;
    cout << setw(20) << left << "Movie Title: " << movie.title << endl;
    cout << setw(20) << left << "Movie Director: " << movie.director << endl;
    cout << setw(20) << left << "Release Year: " << movie.releaseYear << endl;
    cout << setw(20) << left << "Running Time: " << movie.runningTime << " min" << endl;
}