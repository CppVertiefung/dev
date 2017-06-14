#include "tcustomer.h"

using namespace std;

TCustomer::TCustomer()
{
    //ctor
}

TCustomer::~TCustomer()
{
    //dtor
}

TCustomer::TCustomer(const TCustomer& other)
{
    //copy ctor
}

TCustomer& TCustomer::operator=(const TCustomer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
