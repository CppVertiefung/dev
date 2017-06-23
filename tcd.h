/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tcd.h
 * Author: gabriel
 *
 * Created on 23. Juni 2017, 14:58
 */

#ifndef TCD_H
#define TCD_H

#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "tmedium.h"

namespace std {

    class TCD : virtual public TMedium {
    private:
        string interpret;
        int tracks;
    public:
        TCD();
        TCD(string interpret, int tracks);
        virtual ~TCD();

        void load(ifstream &stream);
        void print();
        void setInterpret(string interpret);
        string getInterpret();
        void setTracks(int tracks);
        int getTracks();
    };
}

#endif /* TCD_H */
