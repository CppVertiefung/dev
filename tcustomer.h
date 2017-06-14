#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <tperson.h>


class tcustomer : public tperson
{
    public:
        tcustomer();
        virtual ~tcustomer();
        tcustomer(const tcustomer& other);
        tcustomer& operator=(const tcustomer& other);

        unsigned int GetCustomerNr() { return CustomerNr; }
        void SetCustomerNr(unsigned int val) { CustomerNr = val; }

    protected:

    private:
        unsigned int CustomerNr;
};

#endif // TCUSTOMER_H
