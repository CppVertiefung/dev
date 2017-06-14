#include "temployee.h"

using namespace std;

TEmployee::TEmployee()
{
    //ctor
}

TEmployee::~TEmployee()
{
    //dtor
}

TEmployee::TEmployee(const TEmployee& other)
{
    //copy ctor
}

TEmployee& TEmployee::operator=(const TEmployee& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
