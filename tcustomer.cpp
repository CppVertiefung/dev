#include "tcustomer.h"

tcustomer::tcustomer()
{
    //ctor
}

tcustomer::~tcustomer()
{
    //dtor
}

tcustomer::tcustomer(const tcustomer& other)
{
    //copy ctor
}

tcustomer& tcustomer::operator=(const tcustomer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
