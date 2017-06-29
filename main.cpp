#include <iostream>

using namespace std;

#include "tlibrarypool.h"
//#include "tmedium.h"
//#include "tdate.h"
//#include "tparser.h"

int main() {
    TLibraryPool LP("data.xml");

    LP.print();
    cout << LP << endl;
    
    
    // Tests:
    // Test TDate operator+
//    TDate date1 = TDate(1, 1, 1999);
//    TDate date2 = date1 + 63;
//    
//    date1.print();
//    date2.print();
    
//    TMedium test = TMedium();
//    test.setAgeRestriction(69);
//    cout << test;
//    
//    TPrintedMedium pm = TPrintedMedium();
//    pm.setPages(88);
//    cout << pm;
//    
//    TBook b = TBook();
//    b.setPages(100);
//    b.setTitle("Peniswelten");
//    cout << b;
//    
//    TAudioBook ab = TAudioBook();
//    ab.setPages(1000);
//    ab.setTitle("AudioBuch");
//    cout << ab;
//    
//    TCD cd = TCD();
//    cd.setTitle("CD of SHITE");
//    cd.setTracks(10000);
//    cout << cd;
//    
//    TDVD dvd = TDVD();
//    dvd.setTitle("DVD of Pillermann");
//    dvd.setDuration(TTime());
//    cout << dvd;

    return 0;
}