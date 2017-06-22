#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include "tcustomer.h"

namespace std {

    class TEmployee : public TCustomer {
    public:
        TEmployee(string nr);
        TEmployee();
        virtual ~TEmployee();
//        TEmployee(const TEmployee& other);
//        TEmployee& operator=(const TEmployee& other);
        void load(ifstream &stream);
        void setEmployeeNr(string val);
        string getEmployeeNr();

    protected:
        string EmployeeNr;
    private:
    };

}

#endif // TEMPLOYEE_H
