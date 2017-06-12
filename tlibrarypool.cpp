/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tlibrarypool.cpp
 * Author: gabriel
 * 
 * Created on 4. Mai 2017, 13:56
 * Updated on 04. June 2017 by phil
 */

#include <fstream>
#include <assert.h>

#include "tlibrarypool.h"

using namespace std;

TLibraryPool::TLibraryPool(string name, TPerson* chief) { // : chief(chief) 
    setName(name);
}

TLibraryPool::~TLibraryPool() {
    delete chief;
    for (TLibrary *l : libraries) delete l;
    for (TPerson *p : customers) delete p;
}

TLibraryPool::TLibraryPool(string filename) {
    ifstream input(filename.c_str());
    string line;
    string tag;
    TPerson * pers;
    TLibrary * lib;
    TPerson * cust;
    //    input.open(filename.c_str(), ifstream::in);
    if (input.is_open()) {
        getline(input, line);
        if (line.find("<LibraryPool>") != string::npos) {
            //        load(input);
            string line;
            do {
                getline(input, line);
                if (line.find("<Name>") != string::npos) {
                    name = parseLine(line);
                }
                if (line.find("<Chairman>") != string::npos) {
                    getline(input, line);
                    if (line.find("<Person>") != string::npos) {
                        pers = new TPerson();
                        pers->load(input);
                        chief = pers;
                    }
                }
                if (line.find("<Library>") != string::npos) {
                    lib = new TLibrary();
                    lib->load(input);
                    add(lib);
                }
                if (line.find("<Customer>") != string::npos) {
                    getline(input, line); // test
                    if (line.find("<Person>") != string::npos) {
                        cust = new TPerson();
                        cust->load(input);
                        add(cust);
                    }
                }
                if (input.eof()) {
                    printf("\nERROR: EOF in TLibraryPool::load()\n\n");
                    break;
                }
            } while (line.find("</LibraryPool>") == string::npos);
        }
        input.close();
    } else printf("ERROR: Could not open File");
}

void TLibraryPool::add(TLibrary* library) {
    libraries.push_back(library);
}

void TLibraryPool::add(TPerson* customer) {
    customers.push_back(customer);
}

void TLibraryPool::print() {
    string str = getName();
    printf("Leitung: %s\n", str.c_str());
    chief->print();
    int num = libraries.size();
    printf("\nZum Buechereiverband gehoeren %i Filialen:\n", num);
    for (unsigned int i = 0; i < libraries.size(); i++) {
        libraries.at(i)->print();
        printf("\n");
    }
    printf("\nDer Buechereiverband hat %lu Kunden:\n\n", customers.size());
    for (unsigned int i = 0; i < customers.size(); i++) {
        customers.at(i)->print();
        printf("\n");
    }
    printf("\n");
}

void TLibraryPool::setName(string name) {
    this->name = name;
}

string TLibraryPool::getName() {
    return name;
}