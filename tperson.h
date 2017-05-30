 /* 
 * File:   tperson.h
 * Author: phil
 *
 * Created on 25. April 2017, 23:20
 * Updated on 30. may 2017 by phil
 */
 
#ifndef TPERSON_H
#define TPERSON_H
 
#include <string>
#include "taddress.h"
#include "tdate.h"

namespace std {

    class TPerson {
    private:
        string name;
        TAddress address;
        TDate birth;

    public:
        //	TPerson();
        TPerson(string name, TAddress address, TDate birth);
        ~TPerson();

        void setName(string name);
        void setAddress(TAddress address);
        void setBirth(TDate birth);
		TPerson load(ifstream stream);

        string getName();
        TAddress getAddress();
        TDate getBirth();

        void print();
    };

} // std
#endif /* TPERSON_H */