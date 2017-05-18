/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tdate.h"
#include "ctime" //muss included sein da es sonst auf meinem Rechner nicht Kompiliert... Windoof halt -Tobias

TDate::TDate(unsigned char day, unsigned char month, int year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

TDate::TDate() {
    setCurrentDate();
}

TDate::parseLine(line) {
    if (string slash =line.find("/")){
        int endtag=line.find(">");
        line.erase(0,slash);
        int starttag=line.find("<");
        int endtag=line.find(">");
        int length=endtag - starttag;
        string tag=line.substr(starttag,endtag);
        return (tag);
    }else{
        int starttag=line.find("<");
        int endtag=line.find(">");
        int length=endtag - starttag;
        string tag=line.substr(starttag,endtag);
        return (tag);
    }

}

TDate::load(ifstream stream){
    string line;
    getline(stream,line);
    string tag TDate::parseLine(string line);
    if (tag=="Birthday"){
        getline(stream,line);
        tag =TDate::parseLine(line);
        if (tag=="Date"){
            getline(stream,line);
            unsigned char day =TDate::parseLine(line);
            getline(stream,line);
            unsigned char month =TDate::parseLine(line);
            getline(stream,line);
            int year =atoi(TDate::parseLine(line));
            setYear(year);
            setMonth(month);
            setDay(day);
            getline(stream,line);

        }else{
            cout << "Something weng wrong!!!" <<endl;
        }
        getline(stream,line);
    }else{
        cout << "Something weng wrong!!!" <<endl;
    }
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



