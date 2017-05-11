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

TLibrary::TLibrary(string name, TAddress address, TPerson* manager) : address(address), manager(manager){
    setName(name);
}

void TLibrary::add(TMedium* medium) {
    media.push_back(medium);
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




