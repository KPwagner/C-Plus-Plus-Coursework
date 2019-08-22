/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: kyle
 *
 * Created on July 20, 2019, 2:22 PM
 */



#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


class TimeOff
{
    private:
        string employeeName;
        int employeeID;
        NumDays maxSickDays;
        NumDays sickTaken;
        NumDays maxVacation;
        NumDays vacTaken;
        NumDays maxUnpaid;
        NumDays unpaidTaken;
    public:
        // default constructor
        TimeOff()
        {
            employeeName = "";
            employeeID = -1;
            maxSickDays.setWorkDays(0);
            sickTaken.setWorkDays(0);
            maxVacation.setWorkDays(0);
            vacTaken.setWorkDays(0);
            maxUnpaid.setWorkDays(0);
            unpaidTaken.setWorkDays(0);
        }
        
        // constructor that sets all TimeOff member variables
        // parameter names are a bit convoluted; they correspond to the list of
        // member variables in the private declarations
        TimeOff(string eN, int eID, 
                double maxSD, double sickT, double maxV, 
                double vacationT, double maxU, double unpaidT)
        {
            employeeName = eN;
            employeeID = eID;
            maxSickDays.setWorkDays(maxSD);
            sickTaken.setWorkDays(sickT);
            maxVacation.setWorkDays(maxV);
            vacTaken.setWorkDays(vacationT);
            maxUnpaid.setWorkDays(maxU);
            unpaidTaken.setWorkDays(unpaidT);
        }
        
        // mutator member functions
        void setEmployeeName(string n)
        {
            employeeName = n;
        }
        
        void setEmployeeID(int ID)
        {
            employeeID = ID;
        }
        
        void setMaxSickDays(double d)
        {
            maxSickDays.setWorkDays(d);
        }
        
        void setSickTaken(double d)
        {
            sickTaken.setWorkDays(d);
        }
        
        void setMaxVacation(double d)
        {
            double maxVacationHours = d * 8;
            if (maxVacationHours > 240)
                maxVacation.setWorkHours(240);
            else
                maxVacation.setWorkDays(d);
        }
        
        void setVacTaken(double d)
        {
            vacTaken.setWorkDays(d);
        }
        
        void setMaxUnpaid(double d)
        {
            maxUnpaid.setWorkDays(d);
        }
        
        void setUnpaidTaken(double d)
        {
            unpaidTaken.setWorkDays(d);
        }
        
        // accessor member functions
        string getEmployeeName() const
        {
            return employeeName;
        }
        
        int getEmployeeID() const
        {
            return employeeID;
        }
        
        void getMaxSickDays() const
        {
            maxSickDays.getWorkDays();
        }
        
        void getSickTaken() const
        {
            sickTaken.getWorkDays();
        }
        
        void getMaxVacation() const
        {
            maxVacation.getWorkDays();
        }
        
        void getVacTaken() const
        {
            vacTaken.getWorkDays();
        }
        
        void getMaxUnpaid() const
        {
            maxUnpaid.getWorkDays();
        }
        
        void getUnpaidTaken() const
        {
            unpaidTaken.getWorkDays();
        }
        
        void print() const
        {
            cout << "EMPLOYEE SUMMARY" << endl;
            cout << "Employee Name:\t\t" << employeeName << endl;
            cout << "Employee ID:\t\t" << employeeID << endl;
            cout << "Max Sick Days:\t\t" << maxSickDays.getWorkDays() << endl;
            cout << "Sick Days Taken:\t" << sickTaken.getWorkDays() << endl;
            cout << "Max Vacation:\t\t" << maxVacation.getWorkDays() << endl;
            cout << "Vacation Taken:\t\t" << vacTaken.getWorkDays() << endl;
            cout << "Max Unpaid Vacation:\t" << maxUnpaid.getWorkDays() << endl;
            cout << "Unpaid Vacation Taken:\t" << unpaidTaken.getWorkDays() << endl;
        }
};




#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* TIMEOFF_H */

