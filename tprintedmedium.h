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
#include <iostream>


#include "tmedium.h"


namespace std {

    class TPrintedMedium : virtual public TMedium {
    protected:
        int pages;

    public:
        TPrintedMedium();
        TPrintedMedium(int pages);
        virtual ~TPrintedMedium();

        virtual ostream& printStream(ostream& ostr);
        virtual void load(ifstream &stream);
        friend ostream & operator<<(ostream &ostr, TPrintedMedium &pm);
        void setPages(int pages);
        int getPages();
    };

}


#endif /* TPRINTEDMEDIUM_H */
