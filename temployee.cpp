#include "temployee.h"

using namespace std;

TEmployee::TEmployee(string nr) {
    this->EmployeeNr = nr;
}

TEmployee::TEmployee() {
    setEmployeeNr("");
}

TEmployee::~TEmployee() {
    printf("Der Angestellte '%s' wird vernichtet!\n", getName().c_str());
}

//TEmployee::TEmployee(const TEmployee& other) {
    //copy ctor
//}

//TEmployee& TEmployee::operator=(const TEmployee& rhs) {
//    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
//    return *this;
//}
ostream & TEmployee::printStream(ostream &ostr) {
    ostr << "name " <<"(Kundennummer.: " << getCustomerNr() <<" / Personalnummer.: " << getEmployeeNr() << ")"<< endl;
    return ostr;
}

ostream & std::operator<<(ostream &ostr, TEmployee&emp) {
    emp.printStream(ostr);
}
void TEmployee::print() {
    cout << getName() << " (Kundennr.: " << getCustomerNr() << " / Personalnr.: " << getEmployeeNr() << ")" << endl
            << getAddress().getStreet() << " " << getAddress().getNumber() << "; "
            << getAddress().getZipcode() << " " << getAddress().getTown() << endl
            << "* " << getBirth().getDay() << "." << getBirth().getMonth() << "." << getBirth().getYear() << endl;
}

void TEmployee::load(ifstream &stream) {
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
        } else if (line.find("<EmployeeNr>") != string::npos) {
            setEmployeeNr(parseLine(line));
        } else if (line.find("<CustomerNr>") != string::npos) {
            setCustomerNr(parseLine(line));
        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TCustomer::load()\n");
            break;
        }
    } while (line.find("</Employee>") == string::npos);
}

void TEmployee::setEmployeeNr(string val) {
    this->EmployeeNr = val;
}

string TEmployee::getEmployeeNr() {
    return EmployeeNr;
}
