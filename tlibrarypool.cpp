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

TLibraryPool::TLibraryPool(string name, TEmployee* chief) : chief(chief) { // : chief(chief)
    setName(name);
}

TLibraryPool::~TLibraryPool() {
    delete chief;
    for (TLibrary *l : libraries) delete l;
    for (TPerson *p : customers) delete p;
    for (TLoan *l : loans) delete l;
}

TLibraryPool::TLibraryPool(string filename) {
    cout <<"Datei Data.xml wird geöffnet";
    ifstream input(filename);
    cout << " - ok" << endl << "Datei wird eingelesen ";
    string line;
    string tag;
    TCustomer * cust;
    TEmployee * empl;
    TLibrary * lib;
    TLoan *loan;
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
                    TPerson * pers;
                    TMedium * med;
                    TDate tempdate;
                    int tempduration;
                    do {
                        getline(input, line);
                        if (line.find("<Signatur>") != string::npos) {
                            sig = parseLine(line);
                        }
                        if (line.find("<CuistomerNr>") != string::npos) {
                            nr = parseLine(line);
                        }
                        if (line.find("<LoanDate>") != string::npos) {
                            tempdate.load(input);
                        }
                        if (line.find("<LoanDays>") != string::npos) {
                            tempduration=stoi(parseLine(line));
                        }

                    } while (line.find("</Loan>") == string::npos);
                    for (unsigned int i = 0; i < libraries.size(); i++) {
                        for (unsigned int j = 0; j < libraries.at(i)->media.size(); j++) {
                            if (libraries.at(i)->media.at(j)->getSignature()== nr){
                                med=libraries.at(i)->media.at(j);
                            }
                        }
                    }
                    for (unsigned int j = 0; j < customers.size(); j++) {
                        if (customers.at(j)->getCustomerNr()== nr){
                            pers=customers.at(j);
                        }
                    }
                    loan = new TLoan(pers,med,tempdate,tempduration);
                    add(loan);
                }
                if (input.eof()) {
                    printf("\nERROR: EOF in TLibraryPool::load()\n\n");
                    break;
                }
            } while (line.find("</LibraryPool>") == string::npos);
        }
        input.close();
        cout <<" ok" << endl<< endl<< endl;
    } else printf("ERROR: Could not open File");
}

void TLibraryPool::add(TLibrary* library) {
    libraries.push_back(library);
}


/*bool TLibraryPool::ident1(TCustomer person) {
    return (nr == person.getCustomerNr());
}

bool TLibraryPool::ident3(TMedium med) {
    return (sig == med.getSignature());
}
*/
void TLibraryPool::add(TCustomer* customer) {
    customers.push_back(customer);
}

void TLibraryPool::add(TLoan* loan) {
    loans.push_back(loan);
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
    }    printf("\nFolgende %lu Medien sind ausgeliehen:\n\n", loans.size());
    for (unsigned int i = 0; i < loans.size(); i++) {
        loans.at(i)->print();
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }
    printf("\n");
}

ostream & TLibraryPool::printStream(ostream &ostr) {
    ostr << getName() << endl << "Leitung:"<< *chief <<endl<< "Zum Buechereiverband gehoeren "  <<libraries.size() << " Filialen" << endl << endl;
    for (unsigned int i = 0; i < libraries.size(); i++) {
        //        cout << "DEBUG" << endl << endl;
        libraries.at(i)->printStream(ostr);
    }
    for (unsigned int i = 0; i < customers.size(); i++) {
        //        ostr << customers.at(i) << endl;
        customers.at(i)->print();
    }
    cout << loans.size()<<endl<<endl<<endl;
    for (unsigned int i = 0; i < loans.size(); i++) {
        //        ostr << customers.at(i) << endl;
        loans.at(i)->print();
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

void TLibraryPool::setChief(TEmployee *chief) {
    this->chief = chief;
}

TEmployee * TLibraryPool::getChief() {
    return chief;
}

