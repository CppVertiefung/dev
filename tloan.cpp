#include "tloan.h"

using namespace std;
TLoan::TLoan(TCustomer * cust,TMedium * med,TDate loan,int duration)
{
    this->loaner =cust;
    this->loaned =med;
    this->loandate = loan;
    this->duration = duration;
}

TLoan::~TLoan()
{
    //dtor
}

TCustomer TLoan::getloaner(){
    return *loaner;
}

void TLoan::print(){
    TDate tempdate=(loandate + duration);
    cout << "Ausleihe vom "<<loandate<<endl<<"Rueckgabe bis spaetestens "<<tempdate<<endl<<loaned;
}
ostream& TLoan::printStream(ostream& ostr) {
    TDate tempdate=(loandate + duration);
    ostr<< "Ausleihe vom "<<loandate<<endl<<"Rueckgabe bis spaetestens "<<tempdate<<endl;
    loaned->printStream(ostr);
    //<<loaned<<endl;
    return ostr;
}

ostream& std::operator<<(ostream &ostr, TLoan &l) {
    l.printStream(ostr);
    return ostr;
}
