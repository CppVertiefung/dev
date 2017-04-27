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

class TAddress
{
    private:
        std::string street;
        std::string number;
        std::string zipcode;
        std::string town;

    public:
//        TAddress();
        TAddress(std::string street, std::string number, std::string zipcode, std::string town);

        void setStreet(std::string street);
        void setNumber(std::string number);
        void setZipcode(std::string zipcode);
        void setTown(std::string town);
        std::string getStreet();
        std::string getNumber();
        std::string getZipcode();
        std::string getTown();

        void print();
};


#endif /* TADDRESS_H */
