/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tdvd.h
 * Author: gabriel
 *
 * Created on 23. Juni 2017, 15:45
 */

#ifndef TDVD_H
#define TDVD_H

#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "ttime.h"
#include "tmedium.h"

namespace std {

    class TDVD : public TMedium {
    private:
        string actor;
        TTime duration;
    public:
        TDVD();
        TDVD(string actor, TTime duration);
        ~TDVD();

        void load(ifstream &stream);
        void print();
        void setActor(string actor);
        string getActor();
        void setDuration(TTime duration);
        TTime getDuration();
    };
}

#endif /* TDVD_H */
