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
    cout << "Datei Data.xml wird geöffnet";
    ifstream input(filename);
    cout << " - ok" << endl << "Datei wird eingelesen ";
    string line;
    string tag;
    TCustomer * cust;
    TEmployee * empl;
    TLibrary * lib;
    TLoan *loan;
    TCustomer * pers;
    TMedium * med;
    TDate tempdate;
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

                    int tempduration;
                    do {
                        getline(input, line);
                        if (line.find("<Signatur>") != string::npos) {
                            sig = parseLine(line);
                        }
                        if (line.find("<CustomerNr>") != string::npos) {
                            nr = parseLine(line);
                        }
                        if (line.find("<LoanDate>") != string::npos) {
                            tempdate.load(input);
                        }
                        if (line.find("<LoanDays>") != string::npos) {
                            tempduration = stoi(parseLine(line));
                        }

                    } while (line.find("</Loan>") == string::npos);
                    for (unsigned int i = 0; i < libraries.size(); i++) {
                        for (unsigned int j = 0; j < libraries.at(i)->media.size(); j++) {
                            //                            if (libraries.at(i)->media.at(j)->getSignature() == sig) {
                            string lib_temp = libraries.at(i)->media.at(j)->getSignature();
                            if (lib_temp.compare(sig)) {
                                med = libraries.at(i)->media.at(j);
                                if (!med) {
                                    EXIT_FAILURE;
                                }
                                //                                cout << "med: " << med << endl;
                                med->setStatus("2");
                            }
                        }
                    }
                    for (unsigned int j = 0; j < customers.size(); j++) {
                        //                        if (customers.at(j)->getCustomerNr() == nr) {
                        string cust_temp2 = customers.at(j)->getCustomerNr();
                        if (cust_temp2.compare(nr)) {
                            pers = customers.at(j);
                        }
                    }


                    //                    funktioniert nicht muss aber!
                    loan = new TLoan(pers, med, tempdate, tempduration);

                    add(loan);
                    //                    med->printStream(cout);
                    //                    cout << *loan << endl;
                }
                if (input.eof()) {
                    printf("\nERROR: EOF in TLibraryPool::load()\n\n");
                    break;
                }
            } while (line.find("</LibraryPool>") == string::npos);
        }
        input.close();
        cout << " ok" << endl << endl << endl;
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
    }
    printf("\nFolgende %lu Medien sind ausgeliehen:\n\n", loans.size());
//    for (unsigned int i = 0; i < loans.size(); i++) {
//        loans.at(i)->print();
//        printf("\n");
//        printf("\n");
//        printf("\n");
//        printf("\n");
//    }
    printf("\n");
}

ostream & TLibraryPool::printStream(ostream &ostr) {
    ostr << getName() << endl << "Leitung:" << *chief << endl << "Zum Buechereiverband gehoeren "
            << libraries.size() << " Filialen" << endl << endl;
//    for (unsigned int i = 0; i < libraries.size(); i++) {
    for (vector<TLibrary *>::iterator it = libraries.begin(); it != libraries.end(); it++) {
        //        cout << "DEBUG" << endl << endl;
        (*it)->printStream(ostr);
//        libraries.at(i)->printStream(ostr);
    }
    unsigned int temp = customers.size();
    ostr << "Der Buechereiverband hat " << temp << " Kunden:" << endl;
    for (unsigned int i = 0; i < customers.size(); i++) {
        //        ostr << customers.at(i) << endl;
        customers.at(i)->printStream(ostr);
        for (unsigned int k = 0; k < loans.size(); k++) {
            //Ausgabe der Ausleihen für jeden Kunden
//            string loan_temp = loans.at(k)->getloaner()->getCustomerNr();
            string cust_temp = customers.at(i)->getCustomerNr();
            //            cout << "DEBUG1" << "loan: " << loan_temp << "cust: " << cust_temp << endl;
//            if (loan_temp.compare(cust_temp)) {
//                //                cout << "DEBUG2" << endl;
//                loans.at(k)->printStream(ostr);
//            }
        }
    }
//    for (unsigned int i = 0; i < loans.size(); i++) {
    for (TList<TLoan *>::Iterator it = loans.begin(); it != loans.end(); it++) {
        //        ostr << *customers.at(i) << endl;
//        loans.at(i)->printStream(ostr);
        (*it)->printStream(ostr);
        //        ostr << loans.at(i) << endl;
    }

    return ostr;
}

ostream & std::operator<<(ostream &ostr, TLibraryPool &lp) {
    lp.printStream(ostr);
    return ostr;
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

