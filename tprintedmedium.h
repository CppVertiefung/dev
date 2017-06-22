/* 
 * File:   tprintedmedium.h
 * Author: phil
 *
 * Created on 19. June 2017, 20:55
 * Updated on 
 */

#ifndef TPRINTEDMEDIUM_H
#define TPRINTEDMEDIUM_H

#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>


#include "tmedium.h"


namespace std {

    class TPrintedMedium : public TMedium {
    protected:
        int pages;

    public:
        TPrintedMedium();
        TPrintedMedium(int pages);
        ~TPrintedMedium();

        void load(ifstream &stream);
        void setPages(int pages);
        int getPages();
    };

}


#endif /* TPRINTEDMEDIUM_H */
