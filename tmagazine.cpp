/* 
 * File:   tmagazine.cpp
 * Author: phil
 *
 * Created on 19. June 2017, 23:03
 * Updated on 
 */

#include "tmagazine.h"

using namespace std;

TMagazine::TMagazine(string designer){
    this->designer = designer;
}

TMagazine::TMagazine() {
    this->designer = "";
}

TMagazine::~TMagazine() {
    printf("Das Buch '%s' mit der Signatur '%s' wird vernichtet!\n", title.c_str(), signature.c_str());
}

void TPrintedMedium::load(ifstream &stream) {
    string line;
    TLocation loc;
    do {
        getline(stream, line);
        if (line.find("<Title>") != string::npos) {
            this->title = parseLine(line);
        }
        else if (line.find("<Signatur>") != string::npos) {
            this->signature = parseLine(line);
        }
        else if (line.find("<Location>") != string::npos) {
            loc = TLocation();
            loc.load(stream);
            this->location = loc;
        }
        else if (line.find("<FSK>") != string::npos) {
            this->ageRestriction = atoi(parseLine(line).c_str());
        }
        else if (line.find("<Status>") != string::npos) {
            setStatus(parseLine(line).c_str());
        }
		else if (line.find("<Pages>") != string::npos) {
			this->pages = atoi(parseLine(line).c_str());
		}
		else if (line.find("<designer>") != string::npos) {
            this->designer = parseLine(line);
		}
		
        if (stream.eof()) {
            printf("\nERROR: EOF in TMagazine::load()\n");
            break;
        }
    } while (line.find("</Magazine>") == string::npos);
}


void TMagazine::setDesigner(string designer) {
    this->designer = designer;
}

string TMagazine::getDesigner() {
    return designer;
}