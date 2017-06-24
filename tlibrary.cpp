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

TLibrary::TLibrary() {
    TAddress addr = TAddress();
    TPerson *pers = new TPerson();

    setName("");
    setAddress(addr);
    setManager(pers);
}

TLibrary::~TLibrary() {
    delete manager;
    for (TMedium *m : media) delete m;
}

void TLibrary::load(ifstream &stream) {
    string line;
    TMedium *med;
    TAddress addr;
    TPerson *pers;
    do {
        getline(stream, line);
        if (line.find("<Name>") != string::npos) {
            name = parseLine(line);
        }
        //        if (line.find("<Medium>") != string::npos) {
        //            med = new TMedium();
        //            med->load(stream);
        //            add(med);
        //        }
        if (line.find("<Book>") != string::npos) {
            med = new TBook();
            med->load(stream);
            add(med);
        }
        if (line.find("<Magazine>") != string::npos) {
            med = new TMagazine();
            med->load(stream);
            add(med);
        }
        if (line.find("<Address>") != string::npos) {
            addr = TAddress();
            addr.load(stream);
            address = addr;
        }
        if (line.find("<CD>") != string::npos) {
            med = new TCD();
            med->load(stream);
            add(med);
        }
        if (line.find("<DVD>") != string::npos) {
            med = new TDVD();
            med->load(stream);
            add(med);
        }
        if (line.find("<Audiobook>") != string::npos) {
            med = new TAudioBook();
            med->load(stream);
            add(med);
        }

        if (line.find("<Manager>") != string::npos) {
            getline(stream, line);
            if (line.find("<Employee>") != string::npos) {
                pers = new TEmployee();
                pers->load(stream);
                manager = pers;
            }
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TLibrary::load()\n");
            break;
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

ostream& TLibrary::printStream(ostream& ostr) {
    ostr << "Buecherei: " << getName() << endl;
    getAddress().printStream(ostr);
    getManager()->printStream(ostr);
    ostr << endl;
    for (unsigned int i = 0; i < media.size(); i++) {
//        printf("Medium Nr. %i\n", i + 1);
//        cout << "DEBUG LIB" << endl;
        ostr << "Medium Nr. " << i+1 << endl;
//        ostr << media.at(i) << endl;
//        if(typeid(media.at(i)) == typeid())
//        type_info ti = typeid(media.at(i));
        media.at(i)->printStream(ostr);
    }
    return ostr;
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

