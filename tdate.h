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
 * Updated on 30. may 2017 by phil
 */

#ifndef TDATE_H
#define TDATE_H

#include <stdio.h>
#include "ttime.h"
#include <cstdlib>

class TDate {
private:
    int year;
    unsigned char month;
    unsigned char day;

public:
    TDate();
    TDate(unsigned char day, unsigned char month, int year);

    void setYear(int year);
    void setMonth(unsigned char month);
    void setDay(unsigned char day);
	TDate load(ifstream stream);
    int getYear();
    unsigned char getMonth();
    unsigned char getDay();
    
    void print();
    void setCurrentDate();
};


#endif /* TDATE_H */