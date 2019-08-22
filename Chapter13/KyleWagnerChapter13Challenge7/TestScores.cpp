# include <iostream>
# include "TestScores.h"
using namespace std;

// member functions

// constructors
TestScores::TestScores()
{
    scoreOne = 0.0;
    scoreTwo = 0.0;
    scoreThree = 0.0;
}

TestScores::TestScores(double sOne, double sTwo, double sThree)
{
    scoreOne = sOne;
    scoreTwo = sTwo;
    scoreThree = sThree;
}

// mutator functions
void TestScores::setScoreOne(double sOne)
{
    scoreOne = sOne;
}

void TestScores::setScoreTwo(double sTwo)
{
    scoreTwo = sTwo;
}

void TestScores::setScoreThree(double sThree)
{
    scoreThree = sThree;
}

// accessor functions
double TestScores::getScoreOne()
{
    return scoreOne;
}

double TestScores::getScoreTwo()
{
    return scoreTwo;
}

double TestScores::getScoreThree()
{
    return scoreThree;
}

// other functions
double TestScores::getScoresAverage()
{
    double scoresAverage;
    
    scoresAverage = (scoreOne + scoreTwo + scoreThree) / 3;
    
    return scoresAverage;
}


