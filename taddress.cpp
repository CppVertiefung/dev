/*
 * File:   taddress.cpp
 * Author: phil
 *
 * Created on 25. April 2017, 23:00
 */

using namespace std;

#include "taddress.h"
#include <stdio.h>
#include <fstream>
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
void TAddress::load(ifstream stream){
    string line;
    getline(stream,line);
    string tag= TAddress::parseLine(line);
    if (tag=="Address"){
        string street, number, zipcode, town;
        getline(stream,line);
        street = TAddress::parseLine( line);
        getline(stream,line);
        number= TAddress::parseLine( line);
        getline(stream,line);
        zipcode = TAddress::parseLine( line);
        getline(stream,line);
        town = TAddress::parseLine( line);
        // replace by content of constructor        TAddress::TAddress(street,number,zipcode,town);
        getline(stream,line);
    }else{
        printf("Something weng wrong!!!");
    }
}
string TAddress::parseLine(string line) {
    if (string slash = line.find("/")){
        int endtag=line.find(">");
        line.erase(0,slash);
        int starttag=line.find("<");
        int endtag=line.find(">");
        int length=endtag - starttag;
        string tag=line.substr(starttag,endtag);
        return (tag);
    }else{
        int starttag=line.find("<");
        int endtag=line.find(">");
        int length=endtag - starttag;
        string tag=line.substr(starttag,endtag);
        return (tag);
    }

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
