/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   tmedium.cpp
 * Author: gabriel
 *
 * Created on 3. Mai 2017, 21:18
 */

//#include <qt/QtCore/qstring.h>

#include "tmedium.h"

using namespace std;

TMedium::TMedium(string title, string signature, TLocation location, int ageRestriction, Status status) : location(location), status(status) {
    setTitle(title);
    setSignature(signature);
    setAgeRestriction(ageRestriction);
}

TMedium::~TMedium() {
    printf("Das Medium '%s' mit der Signatur '%s' wird vernichtet!\n", title.c_str(), signature.c_str());
}

void TMedium::load(ifstream stream){
    string line,title,signature,status;
    int age;
    getline(stream,line);
    string tag TMedium::parseLine(string line);
    if (tag=="Medium"){
        getline(stream,line);
        title = TMedium::parseLine(string line);
        getline(stream,line);
        signature = TMedium::parseLine(string line);
        TLocation location =TLocation::load(stream);
        getline(stream,line);
        age=atoi( = TMedium::parseLine(string line));
        getline(stream,line);
        status= TMedium::parseLine(string line);
        TMedium::setTitle(title);
        TMedium::setSignature(signature);
        TMedium::setAgeRestriction(age);
        getline(stream,line);
    }else{
        cout << "Something weng wrong!!!!" <<endl;
    }
}

TMedium::parseLine(string line){
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

void TMedium::print() {
    printf("Titel:      %s\n", title.c_str());
    printf("Signatur:   %s\n", signature.c_str());
    printf("Ort:        ");
    location.print();
    printf("\n");
    printf("FSK:        %i\n", ageRestriction);
    printf("Status:     %s\n", getStatus().c_str());
}

void TMedium::setTitle(string title) {
    this->title = title;
}

void TMedium::setSignature(string signature) {
    this->signature = signature;
}

void TMedium::setLocation(TLocation location) {
    this->location = location;
}

void TMedium::setAgeRestriction(int age) {
    this->ageRestriction = age;
}

void TMedium::setStatus(Status status) {
    this->status = status;
}

string TMedium::getTitle() {
    return title;
}

string TMedium::getSignature() {
    return signature;
}

TLocation TMedium::getLocation() {
    return location;
}

int TMedium::getAgeRestriction() {
    return ageRestriction;
}

string TMedium::getStatus() {
    switch (status) {
        case Status::available:
            return "available";
        case Status::ordered:
            return "ordered";
        case Status::reserved:
            return "reserved";
        case Status::borrowed:
            return "borrowed";
        default:
            return "ERROR TMedium::getStatus()";
    }
}
