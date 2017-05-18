/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   tmedium.h
 * Author: gabriel
 *
 * Created on 3. Mai 2017, 21:18
 */

#ifndef TMEDIUM_H
#define TMEDIUM_H

#include <string>
#include <iomanip>

#include "tlocation.h"


namespace std {

    class TMedium {
    private:
        string title;
        string signature;
        TLocation location;
        int ageRestriction;
 protected:
        string parseLine(string line);
    public:

        enum Status {
            available,
            borrowed,
            ordered,
            reserved
        };

        Status status;
        TMedium(string title, string signature, TLocation location, int ageRestriction, Status status);
        ~TMedium();

        void print();
        void setTitle(string title);
        void setSignature(string signature);
        void setLocation(TLocation location);
        void setAgeRestriction(int age);
        void setStatus(Status status);
        void load(ifstream stream);

        string getTitle();
        string getSignature();
        TLocation getLocation();
        int getAgeRestriction();
        string getStatus();
    };

}


#endif /* TMEDIUM_H */
