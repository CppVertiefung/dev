/* 
 * File:   tlocation.h
 * Author: phil
 *
 * Created on 25. April 2017, 23:58
 * Updated on 04. June 2017 by phil
 */

#ifndef TLOCATION_H
#define TLOCATION_H

//#include <stdio.h>
#include <cstdio>
#include <string>
#include <iomanip>
#include <fstream>

#include "tparser.h"

namespace std {

    class TLocation : public TParser {
    private:
        string section;
        string rack;

    public:
        TLocation();
        TLocation(string section, string rack);

        void setSection(string section);
        void setRack(string rack);
        void load(ifstream &stream);
        string getSection();
        string getRack();

        void print();
    };
}

#endif /* TLOCATION_H */