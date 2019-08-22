// Implementation file for the RetailItem class
# include <iostream>
# include <string>
# include <cstdlib>
# include "RetailItem.h"
using namespace std;

// class member functions

// constructor member functions
RetailItem::RetailItem()
{
    description = "";
    unitsOnHand = 0;
    price = 0.0;
}

RetailItem::RetailItem(string d, int u, double p)
{
    description = d;
    unitsOnHand = u;
    price = p;
}

// mutator member functions
void RetailItem::setDescription(string d)
{
    description = d;
}

void RetailItem::setUnitsOnHand(int u)
{
    unitsOnHand = u;
}

void RetailItem::setPrice(double p)
{
    price = p;
}

// accessor member functions
string RetailItem::getDescription() const
{
    return description;
}

int RetailItem::getUnitsOnHand() const
{
    return unitsOnHand;
}

double RetailItem::getPrice() const
{
    return price;
}

