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

//TPerson()
//{}

TPerson::TPerson(string name, TAddress address, TDate birth) : address(address), birth(birth) {
    setName(name);
}
void TPerson::load(ifstream stream) {
    string line;
    getline(stream,line);
    string tag = TPerson::parseLine(line);
    if (tag=="Person"){
        getline(stream,line);
        tag =TPerson::parseLine(line);
        TPerson::TPerson(tag,Taddress::load,TDate::load(stream));
        tag =TPerson::parseLine(line);
    }else{
        cout << "Something weng wrong!!" <<endl;
    }
}

TPerson::parseLine(line) {
    if (string slash =line.find("/")){
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
TPerson::~TPerson() {
    printf("Die Person '%s' wird vernichtet!\n", name.c_str());
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
