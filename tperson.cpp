/*
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:38
 * Updated on 04. June 2017 by phil
 */

#include "tperson.h"

using namespace std;

TPerson::TPerson(string name, TAddress address, TDate birth) : address(address), birth(birth) {
    this->name = name;
    this->address = address;
    this->birth = birth;
}

TPerson::TPerson() {
    TAddress addr = TAddress();
    TDate date = TDate(0, 0, 0);

    setName("");
    setAddress(addr);
    setBirth(TDate(date));
}

TPerson::~TPerson() {
//    string s = getName();
    printf("Die Person '%s' wird vernichtet!\n", getName().c_str());
}

void TPerson::load(ifstream &stream) {
    string line;
    TDate date;
    TAddress addr;
    do {
        getline(stream, line);
        if (line.find("<Name>") != string::npos) {
            this->name = parseLine(line);
        }
        if (line.find("<Birthday>") != string::npos) {
            getline(stream, line);
            if (line.find("<Date>") != string::npos) {
                date = TDate();
                date.load(stream);
                this->birth = date;
            }
        }
        if (line.find("<Address>") != string::npos) {
            addr = TAddress();
            addr.load(stream);
            this->address = addr;
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TPerson::load()\n");
            break;
        }
    } while (line.find("</Person>") == string::npos);
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
    printf("* ");
    birth.print();
    address.print();
    printf("\n");
}

ostream & TPerson::printStream(ostream& ostr) {
    ostr << getName() << endl;
    ostr << "* ";
    getBirth().printStream(ostr);
    getAddress().printStream(ostr);
    return ostr;
    
}