#include "tcustomer.h"

using namespace std;

TCustomer::TCustomer(string CustomerNr) {
    setCustomerNr(CustomerNr);
}

TCustomer::TCustomer() {
    setCustomerNr("");
}

TCustomer::~TCustomer() {
    printf("Der Kunde'%s' wird vernichtet!\n", getName().c_str());
}

//TCustomer::TCustomer(const TCustomer& other) {
//    //copy ctor
//}
//
//TCustomer& TCustomer::operator=(const TCustomer& rhs) {
//    if (this == &rhs) return *this; // handle self assignment
//    //assignment operator
//    return *this;
//}

void TCustomer::load(ifstream &stream) {
    string line;
    string nr;
    TDate date;
    TAddress addr;
    do {
        getline(stream, line);
        if (line.find("<Name>") != string::npos) {
            setName(parseLine(line));
        }
        if (line.find("<Birthday>") != string::npos) {
            getline(stream, line);
            if (line.find("<Date>") != string::npos) {
                date = TDate();
                date.load(stream);
                setBirth(date);
            }
        }
        if (line.find("<Address>") != string::npos) {
            addr = TAddress();
            addr.load(stream);
            setAddress(addr);
        }
        if (line.find("<CustomerNr>") != string::npos) {
            setCustomerNr(parseLine(line));
        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TCustomer::load()\n");
            break;
        }
    } while (line.find("</Person>") == string::npos);
}

void TCustomer::setCustomerNr(string val) {
    this->CustomerNr = val;
}

string TCustomer::getCustomerNr() {
    return CustomerNr;
}
