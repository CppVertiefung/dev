#include "tloan.h"

using namespace std;

TLoan::TLoan(TPerson * pers,TMedium * med,TDate loan,int duration):loandate (),duration(0)
{
    this->loaner =pers;
    this->loaned =med;
    this->loandate = loan;
    this->duration = duration;
}

TLoan::~TLoan()
{
    //dtor
}

void TLoan::load(ifstream &stream) {
    string line;
    TDate date;
    int dur;
    do{
            getline(stream, line);
            if (line.find("<Date>") != string::npos) {
                date = TDate();
                date.load(stream);
                this->loandate = date;
            }
            if (line.find("<LoanDays>") != string::npos) {
                this->duration = atoi(parseLine(line).c_str());
            }
    }while(line.find("</loan>") == string::npos);
}
