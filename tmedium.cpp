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

TMedium::TMedium() {
    TLocation loc = TLocation();
    setTitle("");
    setSignature("");
    setLocation(loc);
    setAgeRestriction(0);
    setStatus(Status::reserved);
}

TMedium::~TMedium() {
    printf("Das Medium '%s' mit der Signatur '%s' wird vernichtet!\n", title.c_str(), signature.c_str());
}

void TMedium::load(ifstream &stream) {
    string line;
    TLocation loc;
    do {
        getline(stream, line);
        if (line.find("<Title>") != string::npos) {
            this->title = parseLine(line);
        }
        if (line.find("<Signatur>") != string::npos) {
            this->signature = parseLine(line);
        }
        if (line.find("<Location>") != string::npos) {
            loc = TLocation();
            loc.load(stream);
            this->location = loc;
        }
        if (line.find("<FSK>") != string::npos) {
            this->ageRestriction = atoi(parseLine(line).c_str());
        }
        if (line.find("<Status>") != string::npos) {
            setStatus(parseLine(line).c_str());
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TMedium::load()\n");
            break;
        }
    } while (line.find("</Medium>") == string::npos);
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

void TMedium::setStatus(string line) {
    if (line == "1")
        status = Status::available;
    else if (line == "2")
        status = Status::borrowed;
    else if (line == "3")
        status = Status::ordered;
    else
        status = Status::reserved;
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