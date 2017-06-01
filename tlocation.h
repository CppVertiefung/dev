/* 
 * File:   tlocation.h
 * Author: phil
 *
 * Created on 25. April 2017, 23:58
 * Updated on 30. may 2017 by phil
 */

#ifndef TLOCATION_H
#define TLOCATION_H

#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>

namespace std {

    class TLocation {
    private:
        string section;
        string rack;

    public:
        //        TLocation();
        TLocation(string section, string rack);

        void setSection(string section);
        void setRack(string rack);
        TLocation load(ifstream stream);
        string getSection();
        string getRack();

        void print();
    };
}

#endif /* TLOCATION_H */