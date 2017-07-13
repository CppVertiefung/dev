#ifndef TLOAN_H
#define TLOAN_H

#include "tdate.h"
#include "tcustomer.h"
#include "tperson.h"
#include "tmedium.h"
#include "tparser.h"

namespace std {

    class TLoan : public TParser {
    public:
        TLoan(TCustomer* cust, TMedium * med, TDate loan, int duration);
        ~TLoan();
        void print();
        virtual ostream& printStream(ostream &ostr);
        friend ostream & operator<<(ostream &ostr, TLoan &b);
        TCustomer * getloaner();
    protected:

    private:
        TCustomer * loaner;
        TMedium * loaned;
        TDate loandate;
        int duration;

    };
}
#endif // TLOAN_H
