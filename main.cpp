/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: gabriel
 *
 * Created on 18. April 2017, 14:06
 */

//#include <QApplication>
#include <iostream>
#include <stdlib.h>

using namespace std;

#include "tdate.h"
#include "ttime.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    TDate D1, D2(1, 5, 2017);
    TTime T1, T2(6, 32, 27), T3(17, 45);
    cout << "\nKlasse TDate:" << endl;
    cout << "Standardkonstruktor Heutiges Datum (D1): ";
    D1.print();
    cout << endl;
    cout << "Konstruktor Tag der Arbeit (D2): ";
    D2.print();
    cout << endl;
    cout << "\nKlasse TTime:" << endl;
    cout << "Standardkonstruktor Aktuelle Uhrzeit (T1): ";
    T1.print();
    cout << endl;
    cout << "Konstruktor Zeit zum Aufstehen (T2): ";
    T2.print();
    cout << endl;
    cout << "Konstruktor Uebungsbeginn (T3): ";
    T3.print();
    cout << endl;

    //QApplication app(argc, argv);

    // create and show your widgets here

    //return app.exec();
    return EXIT_SUCCESS;
}
