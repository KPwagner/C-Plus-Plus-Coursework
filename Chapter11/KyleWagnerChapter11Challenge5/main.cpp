/*  Created by Kyle Wagner for the class C++ (CIS-161-O01)
 *  
 *  Starting Out With C++
 *  Brief Version
 *  Ninth Edition
 *  Tony Gaddis
 * 
 *  Chapter 11 Challenge 5
 *  Weather Statistics Modification: Modify the program that you wrote for 
 *  Programming Challenge 4 (weather statistics, see below) so it defines an 
 *  enumerated data type with enumerators for the months (JANUARY, FEBRUARY, so 
 *  on). The program should use the enumerated type to step through the elements of 
 *  the array.
 * 
 *  Weather Statistics: Write a program that uses a structure to store the 
 *  following weather data for a particular month:
 *      Total Rainfall
 *      High Temperature
 *      Low Temperature
 *      Average Temperature
 * 
 *  The program should have an array of 12 structures to hold weather data for 
 *  an entire year. When the program runs, it should ask the user to enter data 
 *  for each month. (The average temperature should be calculated.) Once the 
 *  data are entered for all the months, the program should calculate and 
 *  display the average monthly rainfall, the total rainfall for the year, the 
 *  highest and lowest temperatures for the year (and the months they occurred 
 *  in), and the average of all the monthly average temperatures.
 * 
 *  Input Validation: Only accept temperatures within the range between -100 and 
 *  +140 degrees Fahrenheit.
 */

# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// Abstract data type declarations
struct MonthlyWeatherData
{
    string monthName;
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

enum Month {    JANUARY, 
                FEBRUARY, 
                MARCH, 
                APRIL, 
                MAY, 
                JUNE, 
                JULY, 
                AUGUST, 
                SEPTEMBER, 
                OCTOBER, 
                NOVEMBER, 
                DECEMBER };

// Function prototypes
void getWeatherData(MonthlyWeatherData weather[], int);
void calcAverageTemp(MonthlyWeatherData [], int);
void showData(MonthlyWeatherData [], int);
void showWeatherSummary(MonthlyWeatherData [], int);

int main()
{
    // Variables
    const int NUM_MONTHS = 12;
    // weather array is initialized with test data
    MonthlyWeatherData weather[NUM_MONTHS] = {
                                                {"January", 1.2, 34.2, -12.2},
                                                {"February", 0, 30.2, -14.4},
                                                {"March", 4.2, 43.5, 2.3},
                                                {"April", 6.1, 56.5, 21.4},
                                                {"May", 4.4, 72.3, 42.5},
                                                {"June", 3.5, 87.6, 53.4},
                                                {"July", 2.4, 96.7, 53.3},
                                                {"August", 3.4, 91.4, 48.6},
                                                {"September", 2.8, 82.5, 46.5},
                                                {"October", 3.4, 73.2, 43.2},
                                                {"November", 1.4, 67.6, 24.3},
                                                {"December", 1.1, 48.6, 2.4}
                                            };
    
    // Welcome message
    cout << "This program collects weather data, then displays the data." << endl;
    
    // Function calls
    getWeatherData(weather, NUM_MONTHS);
    calcAverageTemp(weather, NUM_MONTHS);
    showData(weather, NUM_MONTHS);
    showWeatherSummary(weather, NUM_MONTHS);
 
    // Exit message
    cout << "\nPress [Enter] to exit program." << endl;
    cin.get();
}

// getWeatherData function collects data from user for each month
void getWeatherData(MonthlyWeatherData weather[], int size)
{
    cout << endl;
    cout << "Enter weather statistics for each month." << endl;
    cout << "Rainfall should be in inches, and temperatures should be in degrees F." << endl;
    for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
    {
        cout << endl;
        cout << weather[month].monthName << endl;
        // Collects total rainfall stats from user
        do
        {
            cout << "Total Rainfall:" << endl;
            cin >> weather[month].totalRainfall;
            cin.ignore(20, '\n');    // prevents error from some bad user input
            if (weather[month].totalRainfall < 0)
            {
                cout << "*** enter a non-negative number for " << weather[month].monthName;
                cout << "'s total rainfall ***" << endl;
            }
                
        } while (weather[month].totalRainfall < 0);
        // Collects high temperature stats from user
        do
        {
            cout << "High Temperature:" << endl;
            cin >> weather[month].highTemperature;
            cin.ignore(20, '\n');    // prevents error from some bad user input
            if (weather[month].highTemperature < -100 || weather[month].highTemperature > 140)
            {
                cout << "*** enter a temperature in the range of -100 and +140 degrees F for ";
                cout << weather[month].monthName << " ***" << endl;
            }
        } while (weather[month].highTemperature < -100 || weather[month].highTemperature > 140);
        // Collects low temperature stats from user
        do
        {
            cout << "Low Temperature:" << endl;
            cin >> weather[month].lowTemperature;
            cin.ignore(20, '\n');    // prevents error from some bad user input
            if (weather[month].lowTemperature < -100 || weather[month].lowTemperature > 140)
            {
                cout << "*** enter a temperature in the range of -100 and +140 degrees F for ";
                cout << weather[month].monthName << " ***" << endl;
            }
        } while (weather[month].lowTemperature < -100 || weather[month].lowTemperature > 140);
    }
}

// calcAverageTemp function collects the average temperature for each month 
// and assigns the value to the respective structure variable
void calcAverageTemp(MonthlyWeatherData weather[], int size)
{
    for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
    {
        // Calculates the average temperature for the month at index
        double averageTemperature = (weather[month].highTemperature + weather[month].lowTemperature) / 2;
        // Assigns the calculated average temperature to the month's averageTemperature attribute
        weather[month].averageTemperature = averageTemperature;
    }
}

// showData function displays the weather data in table form
void showData(MonthlyWeatherData weather[], int size)
{
    cout << endl;
    cout << "(rainfall in inches, temperatures in degrees F)" << endl;
    // Table headers
    cout << setw(15) << left << "Month";
    cout << setw(8) << right << "Rain";
    cout << setw(8) << right << "High";
    cout << setw(8) << right << "Low";
    cout << setw(8) << right << "Avg";
    cout << endl;
    cout << setfill('=') << setw(47) << "=" << endl;
    cout << setfill(' ');
    for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
    {
        cout << setw(15) << left << weather[month].monthName; 
        cout << setprecision(1) << fixed;
        cout << setw(8) << right << weather[month].totalRainfall;
        cout << setw(8) << right << weather[month].highTemperature;
        cout << setw(8) << right << weather[month].lowTemperature;
        cout << setw(8) << right << weather[month].averageTemperature;
        cout << endl;
    }
    cout << endl;
}

// showWeatheSummary function displays key weather stats
void showWeatherSummary(MonthlyWeatherData weather[], int size)
{
    double totalAnnualRainfall = 0;
    double averageMonthlyRainfall = 0;
    double highestTemperature = weather[0].highTemperature;
    string highestTemperatureMonth = weather[0].monthName;
    double lowestTemperature = weather[0].lowTemperature;
    string lowestTemperatureMonth = weather[0].monthName;
    double averageMonthlyTemperatureSum = 0;
    double averageMonthlyTemperatureAverage = 0;
    
    for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
    {
        totalAnnualRainfall += weather[month].totalRainfall;
        
        if (weather[month].highTemperature > highestTemperature)
        {
            highestTemperature = weather[month].highTemperature;
            highestTemperatureMonth = weather[month].monthName;
        }
        
        if (weather[month].lowTemperature < lowestTemperature)
        {
            lowestTemperature = weather[month].lowTemperature;
            lowestTemperatureMonth = weather[month].monthName;
        }
        
        averageMonthlyTemperatureSum += weather[month].averageTemperature;
    }
    
    averageMonthlyRainfall = totalAnnualRainfall / size;
    averageMonthlyTemperatureAverage = averageMonthlyTemperatureSum / size;
    
    cout << "Average monthly rainfall for the year was " << setprecision(1) << fixed << averageMonthlyRainfall << " inches" << endl;
    cout << "Total rainfall for the year was " << totalAnnualRainfall << " inches." << endl;
    cout << "The highest temperature for the year was " << highestTemperature;
    cout << " degrees F in the month of " << highestTemperatureMonth << "." << endl;
    cout << "The lowest temperature for the year was " << lowestTemperature;
    cout << " degrees F in the month of " << lowestTemperatureMonth << "." << endl;
    cout << "The average of all monthly average temperatures was " << averageMonthlyTemperatureAverage << " degrees F." << endl;
}


