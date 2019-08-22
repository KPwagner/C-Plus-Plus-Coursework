/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: kyle
 *
 * Created on July 20, 2019, 2:21 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class NumDays
{
    private:
        double numWorkHours;
    public:
        // constructor
        NumDays(double n = 0)
        {
            numWorkHours = n;
        }
        
        // mutator member functions
        void setWorkHours(double h)
        {
            numWorkHours = h;
        }
        
        void setWorkDays(double d)
        {
            numWorkHours = d * 8.0;
        }
        
        // accessor member functions
        double getWorkHours() const
        {
            return numWorkHours;
        }
        
        double getWorkDays() const
        {
            return numWorkHours / 8.0;
        }
        
        // overloaded operator functions
        double operator+(const NumDays &);
        double operator-(const NumDays &);
        NumDays operator++();
        NumDays operator++(int);
        NumDays operator--();
        NumDays operator--(int);
};

double NumDays::operator + (const NumDays &right)
{   
    return numWorkHours + right.numWorkHours;
}

double NumDays::operator - (const NumDays &right)
{
    return numWorkHours - right.numWorkHours;
}

NumDays NumDays::operator++()
{
    ++numWorkHours;
    return *this;
}

NumDays NumDays::operator++(int)
{
    NumDays temp(numWorkHours);
    numWorkHours++;
    return temp;
}

NumDays NumDays::operator--()
{
    --numWorkHours;
    return *this;
}

NumDays NumDays::operator--(int)
{
    NumDays temp(numWorkHours);
    numWorkHours--;
    return temp;
}


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* NUMDAYS_H */

