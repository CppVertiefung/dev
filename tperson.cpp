/* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:38
 */

#include "tperson.h"

using namespace std;

//TPerson::TPerson()
//{
//}

TPerson::TPerson(string name, TAddress address, TDate birth) : address(address), birth(birth) {
    setName(name);
}

void TPerson::setName(string name) {
    this->name = name;
}

void TPerson::setAddress(TAddress address) {
    this->address = address;
}

void TPerson::setBirth(TDate birth) {
    this->birth = birth;
}

string TPerson::getName() {
    return name;
}

TAddress TPerson::getAddress() {
    return address;
}

TDate TPerson::getBirth() {
    return birth;
}

void TPerson::print() {
    printf("%s\n", name.c_str());
    address.print();
    printf("* ");
    birth.print();
}
