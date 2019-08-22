/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: kyle
 *
 * Created on July 12, 2019, 10:25 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
# include <string>
using namespace std;

// class declaration
class RetailItem
{
    private:
        string description;
        int unitsOnHand;
        double price;
    public:
        // constructors
        RetailItem();
        RetailItem(string, int, double);
        
        // mutator functions
        void setDescription(string);
        void setUnitsOnHand(int);
        void setPrice(double);
        
        // accessor functions
        string getDescription() const;
        int getUnitsOnHand() const;
        double getPrice() const;
};

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* RETAILITEM_H */

