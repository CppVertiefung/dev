/*
 * File:   tbook.h
 * Author: phil
 *
 * Created on 19. June 2017, 22:48
 * Updated on
 */

#include "tbook.h"

using namespace std;

TBook::TBook(string author) {
    setAuthor(author);
}

TBook::TBook() {
    setAuthor("");
}

TBook::~TBook() {
    printf("Das Buch '%s' mit der Signatur '%s' wird vernichtet!\n", getTitle().c_str(), getSignature().c_str());
}

void TBook::load(ifstream &stream) {
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
        } else if (line.find("<Author>") != string::npos) {
            setAuthor(parseLine(line));
        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TBook::load()\n");
            break;
        }
    } while (line.find("</Book>") == string::npos);
}

void TBook::print() {
    cout    << "Autor:          " << getAuthor() << endl
            << "Anz. Seiten:    " << getPages() << endl
            << "Titel:          " << getTitle() << endl
            << "Signatur:       " << getSignature() << endl
            << "Ort:            " << "Abt.: " << getLocation().getSection()
                << "; Regal: " << getLocation().getRack() << endl
            << "FSK:            freigegeben ab "
                << getAgeRestriction() << "Jahren" << endl
            << "Status:         " << getStatus() << endl;
}

ostream& TBook::printStream(ostream& ostr) {
    TMedium m = *this;
    ostr<< "Autor:          " << getAuthor() << endl
        << "Anz. Seiten:    " << getPages() << endl;
    m.printStream(ostr);
    return ostr;
}

ostream& std::operator<<(ostream &ostr, TBook &b) {
    b.printStream(ostr);
//    TMedium m = b;
//    m.printStream(ostr);
}

void TBook::setAuthor(string author) {
    this->author = author;
}

string TBook::getAuthor() {
    return author;
}
