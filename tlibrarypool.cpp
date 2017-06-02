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
 * Updated on 30. may 2017 by phil
 */

#include "tlibrarypool.h"

using namespace std;

TLibraryPool::TLibraryPool(string name, TPerson* chief) { // : chief(chief) 
    setName(name);
}

TLibraryPool::TLibraryPool(string filename) {
    ifstream input;
    string line;
    string tag;
    //    if ((input = fopen(filename.c_str(), "r")) == NULL) {
    //    if (input.open(filename)) {
    //        cout << "ERROR: Failed to open file: " << filename << endl;
    //    }
    input.open(filename, ios::in);
    getline(input, line);
    if (line.find("<LibraryPool>") != std::string::npos) {
        //        load(input);
        string line;
        do {
            getline(input, line);
            if (line.find("<Name>") != std::string::npos) {
//                this->name = parseLine(input);
            }
            if (line.find("<Chairman>") != std::string::npos) {
                getline(input, line);
                if (line.find("<Person>") != std::string::npos) {
//                    this->chief = new TPerson::load(stream);
                }
            }
            if (line.find("<Library>") != std::string::npos) {
                TLibraryPool::add(new TLibrary::load(input));
            }
            if (line.find("<Customer>") != std::string::npos) {
                if (line.find("<Person>") != std::string::npos) {
//                    TLibraryPool::add(new TPerson::load(stream));
                }
            }
        } while (line.find("</LibraryPool>") == std::string::npos);
    }
    input.close();
}

void TLibraryPool::load(ifstream stream) {
    string line;
    do {
        getline(stream, line);
        if (line.find("<Name>") != std::string::npos) {
            //this->name = TLibraryPool::parseLine(stream);
        }
        if (line.find("<Chairman>") != std::string::npos) {
            getline(stream, line);
            if (line.find("<Person>") != std::string::npos) {
                //this->chief = new TPerson::load(stream);
            }
        }
        if (line.find("<Library>") != std::string::npos) {
            //TLibraryPool::add(new TLibrary::load(stream));
        }
        if (line.find("<Customer>") != std::string::npos) {
            if (line.find("<Person>") != std::string::npos) {
                //TLibraryPool::add(new TPerson::load(stream));
            }
        }
    } while (line.find("</LibraryPool>") == std::string::npos);
}

string TLibraryPool::parseLine(string line) {
    int start;
    int end;

    if (line.find("/") != std::string::npos) {
        start = line.find(">") + 1;
        end = line.find("</");
        return line.substr(start, end - start);
    } else {
        start = line.find("<") + 1;
        end = line.find(">");
        return line.substr(start, end - start);
    }
}

void TLibraryPool::add(TLibrary* library) {
    libraries.push_back(library);
}

void TLibraryPool::add(TPerson* customer) {
    customers.push_back(customer);
}

void TLibraryPool::print() {
    string str = getName();
    printf("%s\n", str.c_str());
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