 /* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:00
 */
 
#include "taddress.h"

//TAddress::TAddress()
//{}

TAddress::TAddress(std::string street, std::string number, std::string zipcode, std::string town)
{	
	setStreet(street);
	setNumber(number);
	setZipcode(zipcode);
	setTown(town);
}

void TAddress::setStreet(std::string street)
{
	this->street = street;
}

void TAddress::setNumber(std::string number)
{
	this->number = number;
}

void TAddress::setZipcode(std::string zipcode)
{
	this->zipcode = zipcode;
}

void TAddress::setTown(std::string town)
{
	this->town = town;
}

std::string TAddress::getStreet()
{
	return street;
}

std::string TAddress::getNumber()
{
	return number;
}

std::string TAddress::getZipcode()
{
	return zipcode;
}

std::string TAddress::getTown()
{
	return town;
}   
 
void TAddress::print()
{
	printf("%s %s\n%s %s", street, number, zipcode, town);
}
