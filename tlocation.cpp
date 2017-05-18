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

TLocation::load(ifstream stream){
    string line, section, rack;
    getline(stream,line);
    string tag TLocation::parseLine(string line);
    if (tag=="Location"){
        getline(stream,line);
        section=TLocation::parseLine(string line);
        getline(stream,line);
        rack=TLocation::parseLine(string line);
        TLocation::setSection(section);
        TLocation::setRack(rack);
        getline(stream,line);
    }else{
        printf("what happened?");
    }

}

TLocation::parseLine(string line){
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
