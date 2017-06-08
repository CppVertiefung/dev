/* 
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:00
 * Updated on 04. June 2017 by phil
 */


#include "taddress.h"

using namespace std;

//TAddress::TAddress()
//{}

TAddress::TAddress(string street, string number, string zipcode, string town) {
    this->street = street;
    this->number = number;
    this->zipcode = zipcode;
    this->town = town;
}

TAddress::TAddress() {
    setStreet("");
    setNumber("");
    setZipcode("");
    setTown("");
}

void TAddress::load(ifstream &stream) {
    string line;
    do {
        getline(stream, line);
        if (line.find("<Street>") != string::npos) {
            this->street = parseLine(line);
        }
        if (line.find("<Number>") != string::npos) {
            this->number = parseLine(line);
        }
        if (line.find("<Zipcode>") != string::npos) {
            this->zipcode = parseLine(line);
        }
        if (line.find("<Town>") != string::npos) {
            this->town = parseLine(line);
        }
    } while (line.find("</Address>") == std::string::npos);
}

//void TAddress::load(ifstream stream) {
//    string line;
//    do {
//        getline(stream, line);
//        if (line.find("<Street>") != std::string::npos) {
//            //this->street = TLibraryPool::parseLine(stream);
//        }
//        if (line.find("<Number>") != std::string::npos) {
//            //this->number = TLibraryPool::parseLine(stream);
//        }
//        if (line.find("<Zipcode>") != std::string::npos) {
//            //this->zipcode = TLibraryPool::parseLine(stream);
//        }
//        if (line.find("<Town>") != std::string::npos) {
//            //this->town = TLibraryPool::parseLine(stream);
//        }
//    } while (line.find("</Address>") == std::string::npos);
//}

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