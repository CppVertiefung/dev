/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tlibrary.h
 * Author: gabriel
 *
 * Created on 3. Mai 2017, 21:17
 */

#ifndef TLIBRARY_H
#define TLIBRARY_H

#include <vector>
#include <string>
#include "taddress.h"
#include "tperson.h"
#include "tmedium.h"

namespace std {

    class TLibrary {
    private:
        string name;
        TAddress address;
        TPerson *manager;
        vector<TMedium*> media;
        
    public:
        TLibrary(string name, TAddress address, TPerson *manager);
        void add(TMedium* medium);
        void print();
        
        void setName(string name);
        void setAddress(TAddress address);
        void setManager(TPerson *manager);
        
        string getName();
        TAddress getAddress();
        TPerson* getManager();
    };

}

#endif /* TLIBRARY_H */