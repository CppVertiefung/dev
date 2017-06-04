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
 * Updated on 04. June 2017 by phil
 */

#include "tlibrary.h"

using namespace std;

TLibrary::TLibrary(string name, TAddress address, TPerson* manager) : address(address) {
    setName(name);
}

void TLibrary::load(ifstream stream) {
    string line;
    TPerson * pers = new TPerson(0, 0, 0); // geht so nicht - neuer Leerkonstruktor fuer TPerson muss her
    TMedium * med = new TMedium(0, 0, 0, 0, 0); // ebenso
    do {
        getline(stream, line);

        if (line.find("<Name>") != string::npos) {
            this->name = parseLine(line);
        }
        if (line.find("<Medium>") != string::npos) {
            //new Objekt(0, 0, 0, 0, 0) erstellen, mit this->media = objekt.load() Werte zuweisen und danach objekt.add() aufrufen um in Vektor einzufügen, Achtung Zeiger
            this->media.push_back(med->load(stream));
        }
        if (line.find("<Address>") != string::npos) {
            TAddress addr(0, 0, 0, 0);
            this->address = addr.load(stream);
        }
        if (line.find("<Manager>") != string::npos) {
            getline(stream, line);
            if (line.find("<Person>") != string::npos) {
                this->manager = pers->load(stream);
            }
        }
    } while (line.find("</Library>") == std::string::npos);
}

void TLibrary::add(TMedium * medium) {
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

void TLibrary::setManager(TPerson * manager) {
    this->manager = manager;
}

string TLibrary::getName() {
    return name;
}

TAddress TLibrary::getAddress() {
    return address;
}

TPerson * TLibrary::getManager() {
    return manager;
}

