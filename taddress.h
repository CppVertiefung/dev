/*
 * File:   taddress.h
 * Author: phil
 *
 * Created on 23. April 2017, 21:32
 */

#ifndef TADDRESS_H
#define TADDRESS_H

#include <stdio.h>
#include <string>
#include <iomanip>

namespace std {

    class TAddress {
    private:
        string street;
        string number;
        string zipcode;
        string town;
 protected:
        string parseLine(string line);

    public:
        //    TAddress();
        TAddress(string street, string number, string zipcode, string town);

        void setStreet(string street);
        void setNumber(string number);
        void setZipcode(string zipcode);
        void setTown(string town);
		void load(ifstream stream);
        string getStreet();
        string getNumber();
        string getZipcode();
        string getTown();

        void print();
    };

}
#endif /* TADDRESS_H */
