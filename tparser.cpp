/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.cpp
 * Author: gabriel
 * 
 * Created on 2. Juni 2017, 20:13
 */

#include "tparser.h"

using namespace std;

string TParser::parseLine(string line) {
    int start;
    int end;

    if (line.find("/") != string::npos) {
        start = line.find(">") + 1;
        end = line.find("</");
        return line.substr(start, end - start);
    }
//    else {
//        start = line.find("<") + 1;
//        end = line.find(">");
//        return line.substr(start, end - start);
//    }
}