/* 
 * File:   tlocation.h
 * Author: phil
 *
 * Created on 25. April 2017, 23:58
 */

#ifndef TLOCATION_H
#define TLOCATION_H

#include <string>

namespace std {

    class TLocation {
    private:
        string section;
        string rack;

    public:
        TLocation();
        TLocation(string section, string rack);

        void setSection(string section);
        void setRack(string rack);
        string getSection();
        string getRack();

        void print();
    };

} //std

#endif /* TLOCATION_H */
