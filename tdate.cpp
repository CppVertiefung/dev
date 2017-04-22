/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tdate.h"

TDate::TDate() {
    setCurrentDate();
}

TDate::TDate(unsigned char day, unsigned char month, int year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

void TDate::setYear(int year) {
    this->year = year;
}

void TDate::setMonth(unsigned char month) {
    if (month <= 12 && month > 0)
        this->month = month;
    else
        this->month = 1;
}

void TDate::setDay(unsigned char day) {
    if (day <= 31 && day > 0)
        this->day = day;
    else
        this->day = 1;
}

int TDate::getYear() {
    return year;
}

unsigned char TDate::getMonth() {
    return month;
}

unsigned char TDate::getDay() {
    return day;
}

void TDate::print() {
    printf("%02hhu.%02hhu.%04i", day, month, year);
}

void TDate::setCurrentDate() {
    time_t t;
    struct tm *now;

    time(&t);
    now = localtime(&t);

    year = 1900 + now->tm_year;
    month = (unsigned char) now->tm_mon + 1;
    day = (unsigned char) now->tm_mday;
}



