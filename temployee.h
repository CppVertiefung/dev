/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TEmployee.h
 * Author: gabriel
 *
 * Created on 13. Juni 2017, 10:51
 */

#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include <string>
#include <cstdio>

#include "tperson.h"
#include "tparser.h"

namespace std {

    class TEmployee : public TParser, public TPerson {
    private:
        int EmployeeNr;
    public:
        TEmployee();
        TEmployee(TPerson person, int EmployeeNr);
        TEmployee(string name, TAddress address, TDate birth, int EmployeeNr);

        ~TEmployee();

        void setEmployeeNr();
        int getEmployeeNr();

    };

}

#endif /* TEMPLOYEE_H */
