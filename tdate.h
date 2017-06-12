/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tdate.h
 * Author: gabriel
 *
 * Created on 18. April 2017, 16:44
 * Updated on 03. June 2017 by phil
 */

#ifndef TDATE_H
#define TDATE_H

//#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>

#include "ttime.h"
#include "tparser.h"

namespace std {

    class TDate : public TParser{
    private:
        int year;
        int month;
        int day;

    public:
        TDate();
        TDate(int day, int month, int year);

        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);
        void load(ifstream &stream);
        
        int getYear();
        int getMonth();
        int getDay();
        
        void print();
        void setCurrentDate();
};

}
#endif /* TDATE_H */