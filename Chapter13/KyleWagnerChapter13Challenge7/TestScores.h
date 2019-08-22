/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestScores.h
 * Author: kyle
 *
 * Created on July 13, 2019, 12:51 PM
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H
using namespace std;

// TestScores class declaration
class TestScores
{
    private:
        // attributes
        double scoreOne;
        double scoreTwo;
        double scoreThree;
    public:
        // constructors
        TestScores();
        TestScores(double, double, double);
        
        // mutator functions
        void setScoreOne(double);
        void setScoreTwo(double);
        void setScoreThree(double);
        
        // accessor functions
        double getScoreOne();
        double getScoreTwo();
        double getScoreThree();
        
        // other functions
        double getScoresAverage();    
};



#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* TESTSCORES_H */

