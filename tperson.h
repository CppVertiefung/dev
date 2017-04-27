 /* 
 * File:   tperson.h
 * Author: phil
 *
 * Created on 25. April 2017, 23:20
 */
 
#ifndef TPERSON_H
#define TPERSON_H
 
#include <string>

#include "taddress.h"
#include "tdate.h"
 
class TPerson
{
    private:
	std::string name;
	TAddress address;
	TDate birth;
	
    public:
//	TPerson();
	TPerson(std::string name, TAddress address, TDate birth);
	
	void setName(std::string name);
	void setAddress(TAddress address);
	void setBirth(TDate birth);
	std::string getName();
	TAddress getAddress();
	TDate getBirth();
	 
	void print();
};

#endif /* TPERSON_H */
