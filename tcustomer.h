#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include "tperson.h"

namespace std {

    class TCustomer : virtual public TPerson {
    private:
        string CustomerNr;

    public:
        TCustomer(string CustomerNr);
        virtual ~TCustomer();
        TCustomer(const TCustomer& other);
        TCustomer& operator=(const TCustomer& other);

        void load(ifstream &stream);
        void SetCustomerNr(string val);
        string GetCustomerNr();
    };

}

#endif // TCUSTOMER_H
