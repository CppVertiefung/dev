/* 
 * File:   tlocation.cpp
 * Author: phil
 *
 * Created on 26. April 2017, 00:05
 * Updated on 04. June 2017 by phil
 */

#include "tlocation.h"

using namespace std;

TLocation::TLocation(string section, string rack) {
    setSection(section);
    setRack(rack);
}

TLocation::TLocation() {
    section = "";
    rack = "";
}

void TLocation::load(ifstream stream) {
    string line;
    do {
        getline(stream, line);
        if (line.find("<Section>") != string::npos) {
            this->section = parseLine(line);
        }
        if (line.find("<Rack>") != string::npos) {
            this->rack = parseLine(line);
        }
    } while (line.find("</Location>") == string::npos);
}

void TLocation::setSection(string section) {
    this->section = section;
}

void TLocation::setRack(string rack) {
    this->rack = rack;
}

string TLocation::getSection() {
    return section;
}

string TLocation::getRack() {
    return rack;
}

void TLocation::print() {
    printf("Abt.: %s; Regal: %s", section.c_str(), rack.c_str());
}