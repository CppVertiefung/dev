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

#include <stdio.h>
#include "ttime.h"
#include <iostream>

class TTime {
private:
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
public:
    TTime();
    TTime(unsigned char hour, unsigned char minute);
    TTime(unsigned char hour, unsigned char minute, unsigned char second);

    void setSecond(unsigned char second);
    void setMinute(unsigned char minute);
    void setHour(unsigned char hour);

    void print();
    void setCurrentTime();
};

#endif /* TTIME_H */

