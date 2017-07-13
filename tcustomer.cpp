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

void TCustomer::print() {
    cout << getName() << " (Kundennr.: " << getCustomerNr() << ")" << endl
            << getAddress().getStreet() << " " << getAddress().getNumber() << "; "
            << getAddress().getZipcode() << " " << getAddress().getTown() << endl
            << "* " << getBirth().getDay() << "." << getBirth().getMonth() << "." << getBirth().getYear() << endl;
}

void TCustomer::load(ifstream &stream) {
    string line;
    TDate date;
    TAddress addr;
    do {
        getline(stream, line);
        if (line.find("<Name>") != string::npos) {
            setName(parseLine(line));
        } else if (line.find("<Birthday>") != string::npos) {
            getline(stream, line);
            if (line.find("<Date>") != string::npos) {
                date = TDate();
                date.load(stream);
                setBirth(date);
            }
        } else if (line.find("<Address>") != string::npos) {
            addr = TAddress();
            addr.load(stream);
            setAddress(addr);
        } else if (line.find("<CustomerNr>") != string::npos) {
            setCustomerNr(parseLine(line));
        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TCustomer::load()\n");
            break;
        }
    } while (line.find("</Customer>") == string::npos);
}

void TCustomer::setCustomerNr(string val) {
    this->CustomerNr = val;
}

string TCustomer::getCustomerNr() {
    return CustomerNr;
}

ostream & TCustomer::printStream(ostream& ostr) {
    ostr << name << "(Kundennummer.: " << getCustomerNr() << " )" << endl;
    address.print();
    ostr << "* ";
    birth.print();
    return ostr;
}

ostream & std::operator<<(ostream &ostr, TCustomer &c) {
    c.printStream(ostr);
}