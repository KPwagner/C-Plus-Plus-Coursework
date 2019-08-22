/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 6 Challenge 4
 *  Safest Driving Area: Write a program that determines which of five 
 *  geographic regions within a major city (north, south, east, west, and 
 *  central) had the fewest reported automobile accidents last year. It should 
 *  have the following two functions, which are called by main:
 *  
 * > int getNumAccidents() is passed the name of a region. It asks the user 
 *  for the number of automobile accidents reported in that region during the 
 *  last year, validates the input, then returns it. It should be called once 
 *  for each city region.
 * 
 *  > void findLowest() is passed the five accident totals. It determines which 
 *  is the smallest and prints the name of the region, along with its accident 
 *  figure.
 * 
 *  Input Validation: Do no accept an accident number that is less than 0.
 */

# include <iostream>
# include <string>
using namespace std;

// Function prototypes
int getNumAccidents(string);
void findLowest(int, int, int, int, int);

int main()
{
    int north_accidents, south_accidents, east_accidents, west_accidents, central_accidents;
    
    north_accidents = getNumAccidents("North");
    south_accidents = getNumAccidents("South");
    east_accidents = getNumAccidents("East");
    west_accidents = getNumAccidents("West");
    central_accidents = getNumAccidents("Central");
    
    findLowest(north_accidents, south_accidents, east_accidents, west_accidents, central_accidents);
    
    cin.get();
    return 0;
}

int getNumAccidents(string region)
{
    int region_accidents;
    cout << "How many automobile accidents were reported in the " << region;
    cout << " region?" << endl;
    do
    {
        cin >> region_accidents;
        // cin.ignore statement prevents infinite loop if user enters float
        cin.ignore(20, '\n');
        cout << endl;
        if (region_accidents < 0)
        {
            cout << "Cannot enter less than 0 accidents for a region." << endl;
            cout << "Please enter a non-negative value." << endl;
        }
        
    } while(region_accidents < 0);
    
    return region_accidents;
}

void findLowest(int north_accidents, int south_accidents, int east_accidents, int west_accidents, int central_accidents)
{    
    int lowest_accidents = north_accidents;
    string lowest_region = "North";
    
    if (south_accidents < lowest_accidents)
    {
        lowest_accidents = south_accidents;
        lowest_region = "South";
    }
    if (east_accidents < lowest_accidents )
    {
        lowest_accidents = east_accidents;
        lowest_region = "East";
    }
    if (west_accidents < lowest_accidents)
    {
        lowest_accidents = west_accidents;
        lowest_region = "West";
    }
    if (central_accidents < lowest_accidents)
    {
        lowest_accidents = central_accidents;
        lowest_region = "Central";
    }
    
    cout << "The " << lowest_region << " region had the lowest number of accidents at ";
    cout << lowest_accidents << endl;
}