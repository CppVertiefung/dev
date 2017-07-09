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
#include <cstring>
#include <algorithm>
#include <assert.h>

#include "temployee.h"
#include "tcustomer.h"
#include "tperson.h"
#include "tlibrary.h"
#include "tparser.h"
#include "tcd.h"
#include "tdvd.h"
#include "taudiobook.h"
#include "tloan.h"

namespace std {

    class TLibraryPool : public TParser {
    private:
        string name;
        TPerson *chief;
        bool ident1(TCustomer person);
        bool ident3(TMedium med);
        string sig;
        string nr;
        vector<TLibrary*> libraries;
        vector<TCustomer*> customers;
        vector<TLoan*> loans;
    public:
        TLibraryPool(string name, TPerson* chief);
        TLibraryPool(string filename);
        ~TLibraryPool();
        void add(TLibrary* library);
        void add(TCustomer* customer);
        void add(TLoan* loan);
        void print();
        virtual ostream & printStream(ostream & ostr);
        friend ostream & operator<<(ostream &ostr, TLibraryPool &lp);

        void setName(string name);
        //void load(ifstream stream);
        string getName();
        void setChief(TPerson *chief);
        TPerson* getChief();
    };
}

#endif /* TLIBRARYPOOL_H */
