/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ttime.h
 * Author: gabriel
 *
 * Created on 18. April 2017, 16:39
 * Updated on 30. may 2017 by phil
 */

#ifndef TTIME_H
#define TTIME_H

#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

#include "tparser.h"

namespace std {

    class TTime : public TParser {
    private:
        int hour;
        int minute;
        int second;
    public:
        TTime();
        TTime(int hour, int minute);
        TTime(int hour, int minute, int second);

        void load(ifstream &stream);
        void setSecond(int second);
        int getSecond();
        void setMinute(int minute);
        int getMinute();
        void setHour(int hour);
        int getHour();
        //        string getTime();

        void print();
        void setCurrentTime();
    };

}

#endif /* TTIME_H */

