/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//#include <qt/QtCore/qstring.h>
#include "ttime.h"

using namespace std;

TTime::TTime() {
//    setCurrentTime();
    setHour(0);
    setMinute(0);
    setSecond(0);
}

TTime::TTime(int hour, int minute, int second) {
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

TTime::TTime(int hour, int minute) {
    setHour(hour);
    setMinute(minute);
    setSecond(0);
}

void TTime::load(ifstream& stream) {
    string line;
    do {
        getline(stream, line);
        if (line.find("<Hour>") != string::npos) {
            setHour(atoi(parseLine(line).c_str()));
        } else if (line.find("<Minute>") != string::npos) {
            setMinute(atoi(parseLine(line).c_str()));
        }
        if (stream.eof()) {
            printf("\nERROR: EOF in TTime::load()\n");
            break;
        }
    } while (line.find("</Time>") == string::npos);
}

void TTime::setHour(int hour) {
    if (hour < 24 && hour >= 0)
        this->hour = hour;
    else
        this->hour = 0;
}

int TTime::getHour() {
    return hour;
}

void TTime::setMinute(int minute) {
    if (minute < 60 && minute >= 0)
        this->minute = minute;
    else
        this->minute = 0;
}

int TTime::getMinute() {
    return minute;
}

void TTime::setSecond(int second) {
    if (second < 60 && second >= 0)
        this->second = second;
    else
        this->second = 0;
}

int TTime::getSecond() {
    return second;
}

//string TTime::getTime() {
//    return sprintf("%02i:%02i:%02i", hour, minute, second).c_str();
//}

void TTime::print() {
    printf("%02i:%02i:%02i", hour, minute, second);
}

ostream & TTime::printStream(ostream &ostr) {
    return ostr << getHour() << ":" << getMinute() << ":" << getSecond();
}

void TTime::setCurrentTime() {
    time_t t;
    struct tm *now;

    time(&t);
    now = localtime(&t);

    hour = (int) now->tm_hour;
    minute = (int) now->tm_min;
    second = (int) now->tm_sec;
}