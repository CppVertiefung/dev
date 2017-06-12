/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tlibrarypool.h
 * Author: gabriel
 *
 * Created on 4. Mai 2017, 13:56
 * Updated on 30. may 2017 by phil
 */

#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cstring>

#include "tperson.h"
#include "tlibrary.h"
#include "tparser.h"

namespace std {

    class TLibraryPool : public TParser {
    private:
        string name;
        TPerson *chief;
        vector<TLibrary*> libraries;
        vector<TPerson*> customers;
    public:
        TLibraryPool(string name, TPerson* chief);
        TLibraryPool(string filename);
        ~TLibraryPool();
        void add(TLibrary* library);
        void add(TPerson* customer);
        void print();
        void setName(string name);
        //void load(ifstream stream);
        string getName();
    };
}

#endif /* TLIBRARYPOOL_H */
