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

TLibraryPool::TLibraryPool(string name, TPerson* chief) : chief(chief) { // : chief(chief)
    setName(name);
}

TLibraryPool::~TLibraryPool() {
    delete chief;
    for (TLibrary *l : libraries) delete l;
    for (TPerson *p : customers) delete p;
}

TLibraryPool::TLibraryPool(string filename) {
    ifstream input(filename);
    string line;
    string tag;
    TCustomer * cust;
    TEmployee * empl;
    TLibrary * lib;
    TPerson * pers;
    TMedium * med;
    
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
                    if (line.find("<Employee>") != string::npos) {
                        empl = new TEmployee();
                        empl->load(input);
                        chief = empl;
                    }
                }
                if (line.find("<Library>") != string::npos) {
                    lib = new TLibrary();
                    lib->load(input);
                    add(lib);
                }
                if (line.find("<Customer>") != string::npos) {
                    //                    getline(input, line); // test
                    //                    if (line.find("<Person>") != string::npos) {
                    cust = new TCustomer();
                    cust->load(input);
                    add(cust);
                    //                    }
                }
                if (line.find("<Loan>") != string::npos) {

                    do {
                        getline(input, line);
                        if (line.find("<Signatur>") != string::npos) {
                            sig = parseLine(line);
                        }
                        if (line.find("<CuistomerNr>") != string::npos) {
                            nr = parseLine(line);
                        }

                    } while (line.find("</Loan>") == string::npos);
                    vector<TPerson>::iterator it = find_if(customers.cbegin(), customers.cend(), TLibraryPool::ident1); //raussuchen des passenden Elements im Vector
                    pers = &it;
                    for (vector<TLibrary>::iterator it2 = libraries.begin(); it != libraries.end(); ++it) {//Iterieren durch den Vector der Librarys und Überprüfen des inhalts des Vectors in dem jeweiligen Vectorelement
                        vector<TMedium>::iterator it3 = find_if(customers.cbegin(), customers.cend(), TLibraryPool::ident3); //raussuchen des passenden Elements im Vector
                        if (it3) {
                            med = &it3;
                            break;
                        }
                    }
                    //Constuctor für Loan mit den Werten  (pers,med)
                    //loan.load(input);
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

// mann kann in einer statischen funktion nicht auf attribute einer objekt instanz zugreifen
// die funktion muss direkt die instanz eines objektes wissen
// objektreferenz uebergeben ?? #idk

// achso nr als static wuerde gehen, gibts dann aber auch nur einmal fuer alle objekte

bool TLibraryPool::ident1(TCustomer person) {
    return (nr == person.getCustomerNr());
}

/*
bool TLibraryPool::ident2(TLibrary lib){
    return(lib==lib.media.//check lib
    .getCustomerNr());
}*/

// same here

bool TLibraryPool::ident3(TMedium med) {
    return (sig == med.getSignature());
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

ostream & TLibraryPool::printStream(ostream &ostr) {
    ostr << "Leitung:" << getName() << endl
            << "Zum Buechereiverband gehoeren " << libraries.size() << " Filialen" << endl;
    for (unsigned int i = 0; i < libraries.size(); i++) {
        //        cout << "DEBUG" << endl << endl;
        libraries.at(i)->printStream(ostr);
    }
    for (unsigned int i = 0; i < customers.size(); i++) {
        //        ostr << customers.at(i) << endl;
        customers.at(i)->print();
    }
    return ostr;
}

ostream & std::operator<<(ostream &ostr, TLibraryPool &lp) {
    lp.printStream(ostr);
}

void TLibraryPool::setName(string name) {
    this->name = name;
}

string TLibraryPool::getName() {
    return name;
}

void TLibraryPool::setChief(TPerson *chief) {
    this->chief = chief;
}

TPerson * TLibraryPool::getChief() {
    return chief;
}

