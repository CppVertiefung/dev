/* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:00
 */

using namespace std;

#include "taddress.h"

//TAddress::TAddress()
//{}

TAddress::TAddress(string street, string number, string zipcode, string town) {
    setStreet(street);
    setNumber(number);
    setZipcode(zipcode);
    setTown(town);
}

void TAddress::setStreet(string street) {
    this->street = street;
}

void TAddress::setNumber(string number) {
    this->number = number;
}

void TAddress::setZipcode(string zipcode) {
    this->zipcode = zipcode;
}

void TAddress::setTown(string town) {
    this->town = town;
}

string TAddress::getStreet() {
    return street;
}

string TAddress::getNumber() {
    return number;
}

string TAddress::getZipcode() {
    return zipcode;
}

string TAddress::getTown() {
    return town;
}

void TAddress::print() {
    printf("%s %s\n%s %s", street.c_str(), number.c_str(), zipcode.c_str(), town.c_str());
}