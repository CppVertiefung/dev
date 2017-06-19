#include "temployee.h"

using namespace std;

TEmployee::TEmployee(string nr)
{
    this->EmployeeNr = nr;
}

TEmployee::~TEmployee()
{
    printf("Der Angestellte '%s' wird vernichtet!\n", TEmployee::getName());
}

TEmployee::TEmployee(const TEmployee& other)
{
    //copy ctor
}
TEmployee& TEmployee::operator=(const TEmployee& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void TEmployee::load(ifstream &stream) {
    string line;
    TDate date;
    TAddress addr;
    do {
        getline(stream, line);
        if (line.find("<Name>") != string::npos) {
            TPerson::setName(parseLine(line));
        }
        else if (line.find("<Birthday>") != string::npos) {
            getline(stream, line);
            if (line.find("<Date>") != string::npos) {
                date = TDate();
                date.load(stream);
                this->birth = date;
            }
        }
        else if (line.find("<Address>") != string::npos) {
            addr = TAddress();
            addr.load(stream);
            this->address = addr;
        }
        else if (line.find("<CustomerNr>") != string::npos) {
            //TCustomer::SetCustomerNr(parseLine(line));
            this->CustomerNr = parseLine(line);

        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TCustomer::load()\n");
            break;
        }
    } while (line.find("</Person>") == string::npos);
}

void TEmployee::SetCustomerNr(string val){
    this->EmployeeNr = val;

}
