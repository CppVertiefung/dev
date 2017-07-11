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
 * Updated on 03. June 2017 by phil
 */

#ifndef TLIBRARY_H
#define TLIBRARY_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "taddress.h"
#include "tperson.h"
#include "tmedium.h"
#include "tparser.h"
#include "tbook.h"
#include "tmagazine.h"
#include "tcd.h"
#include "tdvd.h"
#include "temployee.h"
#include "tcustomer.h"
#include "taudiobook.h"

namespace std {

    class TLibrary : public TParser {
    private:
        string name;
        TAddress address;
        TEmployee *manager;
    public:
        vector<TMedium*> media;
        TLibrary(string name, TAddress address, TEmployee *manager);
        TLibrary();
        ~TLibrary();

        void add(TMedium* medium);
        void print();
        ostream & printStream(ostream &ostr);

        void setName(string name);
        void setAddress(TAddress address);
        void setManager(TEmployee *manager);

        void load(ifstream &stream);
        string getName();
        TAddress getAddress();
        TEmployee* getManager();
    };

}

#endif /* TLIBRARY_H */
