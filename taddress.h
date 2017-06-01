/* 
 * File:   taddress.h
 * Author: phil
 *
 * Created on 23. April 2017, 21:32
 * Updated on 30. may 2017 by phil
 */

#ifndef TADDRESS_H
#define TADDRESS_H

#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>

namespace std {

    class TAddress {
    private:
        string street;
        string number;
        string zipcode;
        string town;

    public:
        //    TAddress();
        TAddress(string street, string number, string zipcode, string town);

        void setStreet(string street);
        void setNumber(string number);
        void setZipcode(string zipcode);
        void setTown(string town);
        TAddress load(ifstream stream);
        string getStreet();
        string getNumber();
        string getZipcode();
        string getTown();

        void print();
    };

} // namespace std

#endif /* TADDRESS_H */