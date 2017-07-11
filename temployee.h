#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include "tcustomer.h"

namespace std {

    class TEmployee : public virtual TPerson, public TCustomer {
    public:
        TEmployee(string nr);
        TEmployee();
        virtual ~TEmployee();
        TEmployee(const TEmployee& other);
        TEmployee& operator=(const TEmployee& other);
        void print();
        void load(ifstream &stream);
        void setEmployeeNr(string val);
        string getEmployeeNr();
        virtual ostream & printStream(ostream & ostr);
        friend ostream & operator<<(ostream &ostr, TEmployee &emp);
    protected:
        string EmployeeNr;
    private:
    };

}

#endif // TEMPLOYEE_H
