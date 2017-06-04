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
 * Updated on 04. June 2017 by phil
 */

//#include <qt/QtCore/qstring.h>

#include "tmedium.h"

using namespace std;

TMedium::TMedium(string title, string signature, TLocation location, int ageRestriction, Status status) : location(location), status(status) {
    this->title = title;
    this->signature = signature;
    this->ageRestriction = ageRestriction;
}

TMedium::~TMedium() {
    printf("Das Medium '%s' mit der Signatur '%s' wird vernichtet!\n", title.c_str(), signature.c_str());
}

void TMedium::load(ifstream stream) {
    string line;
	TLocation location = TLocation(0, 0);
    do {
        getline(stream, line);
        if (line.find("<Title>") != std::string::npos) {
            this->title = TLibraryPool::parseLine(stream);
        }
        if (line.find("<Signatur>") != std::string::npos) {
            this->signature = TLibraryPool::parseLine(stream);
        }
        if (line.find("<Location>") != std::string::npos) {
            this->location = location.load(stream);
        }
        if (line.find("<FSK>") != std::string::npos) {
            this->ageRestriction = atoi(TLibraryPool::parseLine(stream));
        }
        if (line.find("<Status>") != std::string::npos) {
            this->status = atoi(TLibraryPool::parseLine(stream));
        }
    } while (line.find("</Medium>") == std::string::npos);
}

void TMedium::print() {
    printf("Titel:      %s\n", title.c_str());
    printf("Signatur:   %s\n", signature.c_str());
    printf("Ort:        ");
    location.print();
    printf("\n");
    printf("FSK:        freigegeben ab %i Jahren\n", ageRestriction);
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
    switch (TMedium::status) {
        case TMedium::available:
            return "verfuegbar";
        case TMedium::ordered:
            return "bestellt";
        case TMedium::reserved:
            return "reserviert";
        case TMedium::borrowed:
            return "ausgeliehen";
        default:
            return "ERROR TMedium::getStatus()";
    }
}

/*Status TMedium::getStatus() {
    switch (TMedium::status) {
        case TMedium::available:
            return TMedium::available;
        case TMedium::ordered:
            return TMedium::ordered;
        case TMedium::reserved:
            return TMedium::reserved;
        case TMedium::borrowed:
            return TMedium::borrowed;
        default:
            return "ERROR TMedium::getStatus()";
    }
}*/