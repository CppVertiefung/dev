/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   tlibrary.cpp
 * Author: gabriel
 *
 * Created on 3. Mai 2017, 21:17
 */

#include "tlibrary.h"

using namespace std;

TLibrary::TLibrary(string name, TAddress address, TPerson* manager) : address(address), manager(manager) {
    setName(name);
}

void TLibrary::load(ifstream stream) {
    string line;
    getline(stream, line);
    string tag = TLibrary::parseLine(line);
    if (tag == "Library") {
        //TODO: Kontrollmethode einf�gen die ein Auslesen in Falscher Reihenfolge erm�glicht!
        getline(stream, line);
        string name = TLibrary::parseLine(line);
        TAddress addr = new TAddress(TAddress::load(stream));
        TPerson pers = TPerson(TPerson::load(stream));
        TLibrary::TLibrary(name, addr, pers);
        string name = TLibrary::parseLine(line);
    } else {
        cout << "Something weng wrong!!!!" << endl;
    }
}

TLibrary::parseLine(line) {
    if (string slash = line.find("/")) {
        int endtag = line.find(">");
        line.erase(0, slash);
        int starttag = line.find("<");
        int endtag = line.find(">");
        int length = endtag - starttag;
        string tag = line.substr(starttag, endtag);
        return (tag);
    } else {
        int starttag = line.find("<");
        int endtag = line.find(">");
        int length = endtag - starttag;
        string tag = line.substr(starttag, endtag);
        return (tag);
    }

}

void TLibrary::add(TMedium* medium) {
    media.push_back(medium);
}

void TLibrary::print() {
    printf("\nBuecherei:  %s\n", getName().c_str());
    address.print();
    printf("\n");
    manager->print();
    printf("\n");
    for (unsigned int i = 0; i < media.size(); i++) {
        printf("Medium Nr. %i\n", i + 1);
        media.at(i)->print();
        printf("\n");
    }
}

void TLibrary::setName(string name) {
    this->name = name;
}

void TLibrary::setAddress(TAddress address) {
    this->address = address;
}

void TLibrary::setManager(TPerson *manager) {
    this->manager = manager;
}

string TLibrary::getName() {
    return name;
}

TAddress TLibrary::getAddress() {
    return address;
}

TPerson* TLibrary::getManager() {
    return manager;
}

