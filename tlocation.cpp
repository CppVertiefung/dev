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