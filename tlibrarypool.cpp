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

#include "tlibrarypool.h"

using namespace std;

TLibraryPool::TLibraryPool(string name, TPerson* chief) { // : chief(chief) 
    setName(name);
}

TLibraryPool::TLibraryPool(string filename) {
    ifstream input;
    string line;
    string tag;
    TPerson * pers = new TPerson(0, 0, 0);      // ersetze durch Leerkonstruktor
    TLibrary * lib = new TLibrary(0, 0, 0);     // ersetze durch Leerkonstruktor
    TPerson * cust = new TPerson(0, 0, 0);      // ersetze durch Leerkonstruktor
    //    if ((input = fopen(filename.c_str(), "r")) == NULL) {
    //    if (input.open(filename)) {
    //        cout << "ERROR: Failed to open file: " << filename << endl;
    //    }
    input.open(filename, ios::in);
    getline(input, line);
    if (line.find("<LibraryPool>") != string::npos) {
        //        load(input);
        string line;
        do {
            getline(input, line);
            if (line.find("<Name>") != string::npos) {
                this->name = parseLine(line);
            }
            if (line.find("<Chairman>") != string::npos) {
                getline(input, line);
                if (line.find("<Person>") != string::npos) {
                    this->chief = pers->load(stream);
                }
            }
            if (line.find("<Library>") != string::npos) {
                //new Objekt(0, 0, 0, 0, 0) erstellen, objekt.load() Werte zuweisen und danach objekt.add() aufrufen um in Vektor einzufügen, Achtung Zeiger
                libraries.add(lib->load(stream));
                //this->libraries.add(lib->load(stream)); ich hab echt keine Ahnung, muss libraries vorher als Attribut abgelegt werden???
            }
            if (line.find("<Customer>") != string::npos) {
                if (line.find("<Person>") != string::npos) {
                    //new Objekt(0, 0, 0, 0, 0) erstellen, objekt.load() Werte zuweisen und danach objekt.add() aufrufen um in Vektor einzufügen, Achtung Zeiger
                    customers.add(cust->load(stream));
                }
            }
        } while (line.find("</LibraryPool>") == string::npos);
    }
    input.close();
}

/*void TLibraryPool::load(ifstream stream) {
    string line;
    do {
        getline(stream, line);
        if (line.find("<Name>") != std::string::npos) {
            //this->name = TLibraryPool::parseLine(stream);
        }
        if (line.find("<Chairman>") != std::string::npos) {
            getline(stream, line);
            if (line.find("<Person>") != std::string::npos) {
                this->chief = new TPerson::load(stream);
            }
        }
        if (line.find("<Library>") != std::string::npos) {
            TLibraryPool::add(new TLibrary::load(stream));
        }
        if (line.find("<Customer>") != std::string::npos) {
            if (line.find("<Person>") != std::string::npos) {
                //TLibraryPool::add(new TPerson::load(stream));
            }
        }
    } while (line.find("</LibraryPool>") == std::string::npos);
}*/

//string TLibraryPool::parseLine(string line) {
//    int start;
//    int end;
//
//    if (line.find("/") != string::npos) {
//        start = line.find(">") + 1;
//        end = line.find("</");
//        return line.substr(start, end - start);
//    } else {
//        start = line.find("<") + 1;
//        end = line.find(">");
//        return line.substr(start, end - start);
//    }
//}

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