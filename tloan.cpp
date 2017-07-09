#include "tloan.h"

using namespace std;
TLoan::TLoan(TPerson * pers,TMedium * med,TDate loan,int duration)
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

void TLoan::print(){
    cout << "TLOAN WIRD AUSGEGEBEN" << endl;

    //cout << "Ausleihe vom " << loandate;
}
