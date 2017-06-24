/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tmedium.h
 * Author: gabriel
 *
 * Created on 3. Mai 2017, 21:18
 * Updated on 04. June 2017 by phil
 */

#ifndef TMEDIUM_H
#define TMEDIUM_H

#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "tlocation.h"
#include "tparser.h"


namespace std {

    class TMedium : public TParser {
    public:

        enum Status {
            available = 1,
            borrowed,
            ordered,
            reserved
        };

    protected:
        string title;
        string signature;
        TLocation location;
        int ageRestriction;
        Status status;

    public:
        TMedium();
        TMedium(string title, string signature, TLocation location, int ageRestriction, Status status);
        virtual ~TMedium();

        virtual void print();
        virtual ostream & printStream(ostream &ostr);
        void setTitle(string title);
        void setSignature(string signature);
        void setLocation(TLocation location);
        void setAgeRestriction(int age);
        void setStatus(Status status);
        void setStatus(string line);
        virtual void load(ifstream &stream);
        friend ostream & operator<<(ostream &ostr, TMedium &m);

        string getTitle();
        string getSignature();
        TLocation getLocation();
        int getAgeRestriction();
        string getStatus();
    };

}


#endif /* TMEDIUM_H */
