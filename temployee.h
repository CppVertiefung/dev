#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include "tperson.h"
#include "tcustomer.h"

namespace std {

    class TEmployee : public TPerson {
    public:
        TEmployee();
        virtual ~TEmployee();
        TEmployee(const TEmployee& other);
        TEmployee& operator=(const TEmployee& other);

    protected:

    private:
    };

}

#endif // TEMPLOYEE_H
