/* 
 * File:   tprintedmedium.h
 * Author: phil
 *
 * Created on 19. June 2017, 20:55
 * Updated on 
 */

#include "tprintedmedium.h"

using namespace std;

TPrintedMedium::TPrintedMedium(int pages){
    this->pages = pages;
}

TPrintedMedium::TPrintedMedium() {
    this->pages = 0;
}

TPrintedMedium::~TPrintedMedium() {
    printf("Das Printed-Medium '%s' mit der Signatur '%s' wird vernichtet!\n", title.c_str(), signature.c_str());
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
        if (stream.eof()) {
            printf("\nERROR: EOF in TPrintedMedium::load()\n");
            break;
        }
    } while (line.find("</PrintedMedium>") == string::npos);
}


void TPrintedMedium::setPages(int pages) {
    this->pages = pages;
}

int TPrintedMedium::getPages() {
    return pages;
}