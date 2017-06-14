#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include "tperson.h"

namespace std {

    class TCustomer : public TPerson {
    private:
        unsigned int CustomerNr;

    public:
        TCustomer();
        virtual ~TCustomer();
        TCustomer(const TCustomer& other);
        TCustomer& operator=(const TCustomer& other);

        unsigned int GetCustomerNr();

        void SetCustomerNr(unsigned int val);

    };

}

#endif // TCUSTOMER_H
