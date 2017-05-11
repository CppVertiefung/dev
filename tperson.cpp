 /* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:38
 */
 
#include <string>
#include <stdio.h>
#include "tdate.h"
#include "taddress.h"
#include "tperson.h"

using namespace std;

TPerson()
{}

TPerson(string name, TAddress address, TDate birth)
{
	setName(string name);
	setAddress(TAddress address);
	setBirth(TDate birth);
}

void TPerson::setName(string name)
{
	this->name = name;
}

void TPerson::setAddress(TAddress address)
{
	this->address = address;
}

void TPerson::setBirth(TDate birth)
{
	this->birth = birth;
}

string TPerson::getName()
{
	return name;
}

TAddress TPerson::getAddress()
{
	return address;
}

TDate TPerson::getBirth()
{
	return birth;
}
	 
void TPerson::print()
{
	printf("%s\n", name);
	address.print();
	printf("* ");
	birth.print();
}