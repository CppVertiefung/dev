/* 
 * File:   tbook.h
 * Author: phil
 *
 * Created on 19. June 2017, 22:48
 * Updated on 
 */

#ifndef TBOOK_H
#define TBOOK_H

#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>


#include "tparser.h"
#include "tprintedmedium.h"


namespace std {

    class TBook : public TParser, public TPrintedMedium {
    private:
		string author;

    public:
        TBook();
        TBook(string author);
        ~TBook();


        void load(ifstream &stream);
		void setAuthor(string author);
		string getAuthor();
    };

}


#endif /* TBOOK_H */
