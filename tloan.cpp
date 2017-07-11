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
    TDate temp=(loandate + duration);
    cout << loaner << endl << "Ausleihen" << endl << "Ausleihe vom";
    loandate.print();
    cout << endl << "Rueckgabe bis spaetestens ";
    temp.print();

    //cout << "Ausleihe vom " << loandate;
}
