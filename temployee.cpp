#include "temployee.h"

temployee::temployee()
{
    //ctor
}

temployee::~temployee()
{
    //dtor
}

temployee::temployee(const temployee& other)
{
    //copy ctor
}

temployee& temployee::operator=(const temployee& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
