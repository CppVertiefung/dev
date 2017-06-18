#include "tcustomer.h"

using namespace std;

TCustomer::TCustomer(string CustomerNr="")
{
    this->CustomerNr = CustomerNr;
}

TCustomer::~TCustomer()
{
    printf("Der Kunde'%s' wird vernichtet!\n", TCustomer::getName().c_str());
}

TCustomer::TCustomer(const TCustomer& other)
{
    //copy ctor
}

TCustomer& TCustomer::operator=(const TCustomer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void TCustomer::load(ifstream &stream) {
    string line;
    string nr;
    TDate date;
    TAddress addr;
    do {
        getline(stream, line);
        if (line.find("<Name>") != string::npos) {
            TPerson::setName(parseLine(line));
        }
        if (line.find("<Birthday>") != string::npos) {
            getline(stream, line);
            if (line.find("<Date>") != string::npos) {
                date = TDate();
                date.load(stream);
                this->birth = date;
            }
        }
        if (line.find("<Address>") != string::npos) {
            addr = TAddress();
            addr.load(stream);
            this->address = addr;
        }
        if (line.find("<CustomerNr>") != string::npos) {
            TCustomer::SetCustomerNr(parseLine(line));


            //this->CustomerNr=(parseLine(line));

        }

        if (stream.eof()) {
            printf("\nERROR: EOF in TCustomer::load()\n");
            break;
        }
    } while (line.find("</Person>") == string::npos);
}

void TCustomer::SetCustomerNr(string val){
    this->CustomerNr=val;
}

string TCustomer::GetCustomerNr(){
    return (this->CustomerNr);
}
