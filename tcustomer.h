/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCustomer.h
 * Author: gabriel
 *
 * Created on 12. Juni 2017, 23:47
 */

#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <string>
#include <cstdio>

#include "tperson.h"
#include "tparser.h"

namespace std {
    class TCustomer : public TParser, public TPerson {
    private:
        int CustomerNr;
        
    public:
        TCustomer();
        TCustomer(TPerson person, int CustomerNr);
        TCustomer(string name, TAddress address, TDate birth);
        ~TCustomer() override;

        void setEmployeeNr();
        int getEmployeeNr();
        
        
    };
}

#endif /* TCUSTOMER_H */
