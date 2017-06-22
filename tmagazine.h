/* 
 * File:   tmagazine.h
 * Author: phil
 *
 * Created on 19. June 2017, 23:03
 * Updated on 
 */

#ifndef TMAGAZINE_H
#define TMAGAZINE_H

#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>


#include "tprintedmedium.h"


namespace std {

    class TMagazine : public TPrintedMedium {
    private:
        string designer;

    public:
        TMagazine();
        TMagazine(string designer);
        ~TMagazine();

        void load(ifstream &stream);
        void setDesigner(string designer);
        string getDesigner();
    };

}

#endif /* TMAGAZINE */
