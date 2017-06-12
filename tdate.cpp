/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Updated on 03. June 2017 by phil
 */

#include "tdate.h"

using namespace std;

TDate::TDate() {
    setCurrentDate();
}

TDate::TDate(int day, int month, int year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

void TDate::load(ifstream &stream) {
    string line;
    do {
        getline(stream, line);
        if (line.find("<Day>") != string::npos) {
            this->day = atoi(parseLine(line).c_str());
        }
        if (line.find("<Month>") != string::npos) {
            this->month = atoi(parseLine(line).c_str());
        }
        if (line.find("<Year>") != string::npos) {
            this->year = atoi(parseLine(line).c_str());
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TDate::load()\n");
            break;
        }
    } while (line.find("</Date>") == string::npos);
}

void TDate::setYear(int year) {
    this->year = year;
}

void TDate::setMonth(int month) {
    if (month <= 12 && month > 0)
        this->month = month;
    else
        this->month = 1;
}

void TDate::setDay(int day) {
    if (day <= 31 && day > 0)
        this->day = day;
    else
        this->day = 1;
}

int TDate::getYear() {
    return year;
}

int TDate::getMonth() {
    return month;
}

int TDate::getDay() {
    return day;
}

void TDate::print() {
    printf("%02i.%02i.%04i\n", day, month, year);
}

void TDate::setCurrentDate() {
    time_t t;
    struct tm *now;

    time(&t);
    now = localtime(&t);

    year = 1900 + now->tm_year;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}



