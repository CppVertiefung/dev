#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include <tperson.h>
#include <tcustomer.h>


class temployee : public tperson.h , tcustomer.h
{
    public:
        temployee();
        virtual ~temployee();
        temployee(const temployee& other);
        temployee& operator=(const temployee& other);

    protected:

    private:
};

#endif // TEMPLOYEE_H
