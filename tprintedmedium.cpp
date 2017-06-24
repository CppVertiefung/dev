/* 
 * File:   tprintedmedium.h
 * Author: phil
 *
 * Created on 19. June 2017, 20:55
 * Updated on 
 */

#include "tprintedmedium.h"

using namespace std;

TPrintedMedium::TPrintedMedium(int pages) {
    setPages(pages);
}

TPrintedMedium::TPrintedMedium() {
    setPages(0);
}

TPrintedMedium::~TPrintedMedium() {
    printf("Das Printed-Medium '%s' mit der Signatur '%s' wird vernichtet!\n", getTitle().c_str(), getSignature().c_str());
}

void TPrintedMedium::load(ifstream &stream) {
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
        } else if (line.find("<Pages>") != string::npos) {
            setPages(atoi(parseLine(line).c_str()));
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