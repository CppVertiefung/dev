#ifndef TLOAN_H
#define TLOAN_H
#include "tdate.h"
#include "tperson.h"
#include "tmedium.h"
#include "tparser.h"
namespace std{
class TLoan :public TParser
{
    public:
        TLoan(TPerson * pers, TMedium * med,TDate loan,int duration);
        ~TLoan();
        void load(ifstream &stream);
    protected:

    private:
        TPerson * loaner;
        TMedium * loaned;
        TDate loandate;
        int duration;

};
}
#endif // TLOAN_H
