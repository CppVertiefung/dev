 /* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:38
 */

#include "tperson.h"

//TPerson::TPerson()
//{
//}

TPerson::TPerson(std::string name, TAddress address, TDate birth)
{
	setName(name);
	setAddress(address);
	setBirth(birth);
}

void TPerson::setName(std::string name)
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

std::string TPerson::getName()
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
