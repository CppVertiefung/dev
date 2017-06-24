#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <string>
#include <cstring>
#include <iostream>

#include "tperson.h"

namespace std {

    class TCustomer : public virtual TPerson {
    private:
        string CustomerNr;

    public:
        TCustomer(string CustomerNr);
        TCustomer();
        virtual ~TCustomer();
//        TCustomer(const TCustomer& other);
//        TCustomer& operator=(const TCustomer& other);

        void print();
        void load(ifstream &stream);
        void setCustomerNr(string val);
        string getCustomerNr();
    };

}

#endif // TCUSTOMER_H
