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
#include "tperson.h"

using namespace std;

TLibrary::TLibrary(string name, TAddress address, TPerson* manager){ //: address(address), manager(manager) 
    setName(name);
}

TLibrary * TLibrary::load(ifstream stream){
	string line;
	do{
		getline(stream, line);
		if (stream.find("<Name>") != std::string::npos){
			//this->name = TLibraryPool::parseLine(stream);
		}
		if (stream.find("<Medium>") != std::string::npos){
			getline(stream, line);
			if (stream.find("<Date>") != std::string::npos){	
				//TLibrary::add(new TMedium::load(stream));
		}
		if (stream.find("<Address>") != std::string::npos){
			//this->address = TAddress::load(stream);
		}
		if (stream.find("<Manager>") != std::string::npos){
			getline(stream, line);
			if (stream.find("<Person>") != std::string::npos){	
				//this->manager = new TPerson::load(stream);
			}
		}
	}while(line.find("</Library>") == std::string::npos);
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

