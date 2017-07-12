/*
 * File:   tmagazine.cpp
 * Author: phil
 *
 * Created on 19. June 2017, 23:03
 * Updated on
 */

#include "tmagazine.h"

using namespace std;

TMagazine::TMagazine(string designer) {
    setDesigner(designer);
}

TMagazine::TMagazine() {
    setDesigner("");
}

TMagazine::~TMagazine() {
    printf("Das Magazin '%s' mit der Signatur '%s' wird vernichtet!\n", getTitle().c_str(), getSignature().c_str());
}
ostream& TMagazine::printStream(ostream& ostr) {
    TMedium m = *this;
    ostr<< "Designer:       " << getDesigner() << endl;
    m.printStream(ostr);
    return ostr;
}
ostream& std::operator<<(ostream &ostr, TMagazine &m) {
    m.printStream(ostr);
}

void TMagazine::load(ifstream &stream) {
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
        } else if (line.find("<Designer>") != string::npos) {
            setDesigner(parseLine(line));
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
