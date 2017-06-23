/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   taudiobook.h
 * Author: gabriel
 *
 * Created on 23. Juni 2017, 19:21
 */

#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "tbook.h"
#include "tcd.h"


namespace std {
    class TAudioBook : virtual public TCD, virtual public TBook {
    private:
        int CDs;
    public:
        TAudioBook();
        TAudioBook(int CDs);
        virtual ~TAudioBook();
        
        void load(ifstream &stream);
        void print();
        
        void setCDs(int CDs);
        int getCDs();
    };
}

#endif /* TAUDIOBOOK_H */
