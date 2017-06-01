/* 
 * File:   tlocation.cpp
 * Author: phil
 *
 * Created on 26. April 2017, 00:05
 */

#include "tlocation.h"

using namespace std;

//TLocation()
//{
//	setSection("Buero");
//	setRack("Fach zum Einsortieren");
//}

TLocation::TLocation(string section, string rack) {
    setSection(section);
    setRack(rack);
}

TLocation TLocation::load(ifstream stream) {
    string line;
    do {
        getline(stream, line);
        if (stream.find("<Section>") != std::string::npos) {
            //this->section = TLibraryPool::parseLine(stream);
        }
        if (stream.find("<Rack>") != std::string::npos) {
            //this->rack = TLibraryPool::parseLine(stream);
        }
    } while (line.find("</Location>") == std::string::npos);
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