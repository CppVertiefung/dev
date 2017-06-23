/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tcd.cpp
 * Author: gabriel
 * 
 * Created on 23. Juni 2017, 14:58
 */

#include "tcd.h"

using namespace std;

TCD::TCD(string interpret, int tracks) {
    setInterpret(interpret);
    setTracks(tracks);
}

TCD::TCD() {
    setInterpret("");
    setTracks(0);
}

TCD::~TCD() {
    printf("Die CD '%s' mit der Signatur '%s' wird vernichtet!\n", getTitle().c_str(), getSignature().c_str());
}

void TCD::print() {
    printf("Interpret:      %s\n", getInterpret().c_str());
    printf("Anz. Tracks:    %i\n", getTracks());
    TMedium::print();
}

void TCD::load(ifstream &stream) {
    string line;
    TLocation loc;
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
        } else if (line.find("<Interpret>") != string::npos) {
            setInterpret(parseLine(line));
        } else if (line.find("<Tracks>") != string::npos) {
            setTracks(atoi(parseLine(line).c_str()));
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TCD::load()\n");
            break;
        }
    } while (line.find("</CD>") == string::npos);
}

void TCD::setInterpret(string interpret) {
    this->interpret = interpret;
}

string TCD::getInterpret() {
    return interpret;
}

void TCD::setTracks(int tracks) {
    this->tracks = tracks;
}

int TCD::getTracks() {
    return tracks;
}