/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TEmployee.cpp
 * Author: gabriel
 * 
 * Created on 13. Juni 2017, 10:51
 */

#include "temployee.h"

using namespace std;

TEmployee::TEmployee() {
    EmployeeNr = 0;
}

TEmployee::TEmployee(TPerson person, int EmployeeNr) {

}

TEmployee::TEmployee(string name, TAddress address, TDate birth, int EmployeeNr) :
    TPerson::TPerson(name, address, birth), EmployeeNr(EmployeeNr) {
    // test parameter passing
}

TEmployee::~TEmployee() override {

}

int TEmployee::getEmployeeNr() {
    return EmployeeNr;
}

void TEmployee::setEmployeeNr(int EmployeeNr) {
    this->EmployeeNr = EmployeeNr;
}



