/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   taudiobook.cpp
 * Author: gabriel
 * 
 * Created on 23. Juni 2017, 19:21
 */

#include "taudiobook.h"

using namespace std;

TAudioBook::TAudioBook() {
    setCDs(0);
}

TAudioBook::TAudioBook(int CDs) {
    setCDs(CDs);
}

TAudioBook::~TAudioBook() {
    cout << "Das Audiobook " << getTitle()
            << " mit der Signatur " << getSignature()
            << " wird vernichtet!" << endl;
}

// modularisieren

void TAudioBook::load(ifstream &stream) {
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
        } else if (line.find("<Pages>") != string::npos) {
            setPages(atoi(parseLine(line).c_str()));
        } else if (line.find("<Author>") != string::npos) {
            setAuthor(parseLine(line));
        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TAudioBook::load()\n");
            break;
        }
    } while (line.find("</Audiobook>") == string::npos);
}

// modularisieren

void TAudioBook::print() {
    cout << "Interpret:      " << getInterpret() << endl
            << "Anz. Tracks:    " << getTracks() << endl
            << "Anz. CDs:       " << getCDs() << endl
            << "Autor:          " << getAuthor() << endl
            << "Anz. Seiten:    " << getPages() << endl
            << "Titel:          " << getTitle() << endl
            << "Signatur:       " << getSignature() << endl
            << "Ort:            " << "Abt.: " << getLocation().getSection()
            << "; Regal: " << getLocation().getRack() << endl
            << "FSK:            freigegeben ab "
            << getAgeRestriction() << "Jahren" << endl
            << "Status:         " << getStatus() << endl;
}

ostream & TAudioBook::printStream(ostream& ostr) {
    TCD cd = *this;
    cd.printStream(ostr);
    ostr << "Anz. CDs:    " << getCDs() << endl;
    TBook b = *this;
    b.printStream(ostr);
    TMedium m = *this;
    m.printStream(ostr);
    return ostr << endl;
}

ostream & std::operator<<(ostream &ostr, TAudioBook &ab) {
    ab.printStream(ostr);
}

void TAudioBook::setCDs(int CDs) {
    this->CDs = CDs;
}

int TAudioBook::getCDs() {
    return CDs;
}