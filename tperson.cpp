/* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:38
 * Updated on 04. June 2017 by phil
 */

#include <string>
#include <stdio.h>
#include "tdate.h"
#include "taddress.h"
#include "tperson.h"

using namespace std;

//TPerson()
//{}

TPerson::TPerson(string name, TAddress address, TDate birth) : address(address), birth(birth) {
    this->name = name;
	this->address = address;
	this->birth = birth;
}

TPerson::~TPerson() {
    printf("Die Person '%s' wird vernichtet!\n", name.c_str());
}

TPerson TPerson::load(ifstream stream) {
    string line;
	TDate date = TDate(0, 0, 0);;
    TAddress addr = TAddress(0, 0, 0, 0);
	do {
        getline(stream, line);
        if (line.find("<Name>") != std::string::npos) {
            this->name = TLibraryPool::parseLine(stream);
        }
        if (line.find("<Birthday>") != std::string::npos) {
            getline(stream, line);
            if (line.find("<Date>") != std::string::npos) {
                this->birth = date.load(stream);
            }
        }
        if (line.find("<Address>") != std::string::npos) {
            this->address = addr.load(stream);
        }
    } while (line.find("</Person>") == std::string::npos);
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
    //printf("%s\n", name);
    printf("%s\n", name.c_str());
    address.print();
    printf("* ");
    birth.print();
}
