/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tdvd.cpp
 * Author: gabriel
 * 
 * Created on 23. Juni 2017, 15:45
 */

#include "tdvd.h"

using namespace std;

TDVD::TDVD(string actor, TTime duration) : duration(duration) {
    setActor(actor);
//    setDuration(duration);
}

TDVD::TDVD() {
    setActor("");
    setDuration(TTime());
}

TDVD::~TDVD() {
    printf("Die DVD '%s' mit der Signatur '%s' wird vernichtet!\n", getTitle().c_str(), getSignature().c_str());
}

void TDVD::print() {
    printf("Schauspieler: %s\n", getActor().c_str());
    printf("Spieldauer:  ");
    getDuration().print();
    printf("\n");
    TMedium::print();
}

void TDVD::load(ifstream &stream) {
    string line;
    TLocation loc;
    TTime dur;
    do {
        getline(stream, line);
        if (line.find("<Title>") != string::npos) {
            setTitle(parseLine(line));
        } else if (line.find("<Signatur>") != string::npos) {
            setSignature(parseLine(line));
        } else if (line.find("<Location>") != string::npos) {
            loc = TLocation();
            loc.load(stream);
            setLocation(loc);
        } else if (line.find("<FSK>") != string::npos) {
            setAgeRestriction(atoi(parseLine(line).c_str()));
        } else if (line.find("<Status>") != string::npos) {
            setStatus(parseLine(line).c_str());
        } else if (line.find("<Actors>") != string::npos) {
            setActor(parseLine(line));
        } else if (line.find("<PlayingTime>") != string::npos) {
            dur = TTime();
            dur.load(stream);
            setDuration(dur);
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TDVD::load()\n");
            break;
        }
    } while (line.find("</DVD>") == string::npos);
}

void TDVD::setActor(string actor) {
    this->actor = actor;
}

string TDVD::getActor() {
    return actor;
}

void TDVD::setDuration(TTime duration) {
    this->duration = duration;
}

TTime TDVD::getDuration() {
    return duration;
}