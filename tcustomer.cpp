/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCustomer.cpp
 * Author: gabriel
 * 
 * Created on 12. Juni 2017, 23:47
 */

#include "tcustomer.h"
#include "tperson.h"

using namespace std;

TCustomer::TCustomer() {
    CustomerNr = 0;
}

TCustomer::TCustomer(TPerson person, int CustomerNr) {
    
}

TCustomer::TCustomer(string name, TAddress address, TDate birth, int CustomerNr) :
TPerson::TPerson(name, address, birth) {
//    setName(name);
//    setAddress(address);
//    setBirth(birth);
    
}

TCustomer::~TCustomer(){
}





