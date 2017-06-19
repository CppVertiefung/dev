/* 
 * File:   tbook.h
 * Author: phil
 *
 * Created on 19. June 2017, 22:48
 * Updated on 
 */

#include "tbook.h"

using namespace std;

TBook::TBook(string author){
    this->author = author;
}

TBook::TBook() {
    this->author = "";
}

TBook::~TBook() {
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
		else if (line.find("<Author>") != string::npos) {
            this->author = parseLine(line);
		}
		
        if (stream.eof()) {
            printf("\nERROR: EOF in TBook::load()\n");
            break;
        }
    } while (line.find("</Book>") == string::npos);
}


void TBook::setAuthor(string author) {
    this->author = author;
}

string TBook::getAuthor() {
    return author;
}