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
 */

#include "tlibrarypool.h"
#include <stdio.h>
using namespace std;

TLibraryPool::TLibraryPool(string name, TPerson* chief) : chief(chief) {
    setName(name);
}
TLibraryPool::TLibraryPool(filename){
    FILE * input;
    string line;
    input = fopen(filename,"r");
    if (!input)
    {
        cout << "ERROR READING FILE!" <<endl;
    }else
    {
        getline(input,line);
        string test=parseLine(line);
        if (test=="LibraryPool"){
            TLibraryPool.load(input);
        }
    }
    fclose(input);
}
TLibraryPool::parseLine(line) {
    if (string slash =line.find("/")){
        int endtag=line.find(">");
        line.erase(0,slash);
        int starttag=line.find("<");
        int endtag=line.find(">");
        int length=endtag - starttag;
        string tag=line.substr(starttag,endtag);
        return tag;
    }else{
        int starttag=line.find("<");
        int endtag=line.find(">");
        int length=endtag - starttag;
        string tag=line.substr(starttag,endtag);
        return (tag);
    }

}
void TLibraryPool::load(ifstream stream) { //TODO: auslesen was als nächstes geadded wird und per while abarbeiten. darin mit switch case arbeiten
    string line;
    getline(stream,line);
    string tag = TLibraryPool::parseLine(string line)
    getline(stream,line);
    TLibraryPool.TLibraryPool(string tag, TPerson::load)
    getline(stream,line);
    TLibrary::add(TLibrary::load(stream));
    TLibrary::add(TLibrary::load(stream));
    TLibrary::add(TPerson::load(stream));
    TLibrary::add(TPerson::load(stream));
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
    printf("\nDer Buechereiverband hat %lu Kunden:\n", customers.size());
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
