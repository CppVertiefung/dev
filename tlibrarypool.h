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
 */

#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H

#include <string>
#include <vector>
#include <iomanip>
#include "tperson.h"
#include "tlibrary.h"

namespace std {

    class TLibraryPool {
    private:
        string name;
        TPerson *chief;
        vector<TLibrary*> libraries;
        vector<TPerson*> customers;
    public:
        TLibraryPool(string name, TPerson* chief);
        void add(TLibrary* library);
        void add(TPerson* customer);
        void print();
        void setName(string name);
        
        string getName();
        
    };

}

#endif /* TLIBRARYPOOL_H */
