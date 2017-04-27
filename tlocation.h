/* 
 * File:   tlocation.h
 * Author: phil
 *
 * Created on 25. April 2017, 23:58
 */

#ifndef TLOCATION_H
#define TLOCATION_H

#include <string>

class TLocation
{
    private:
	std::string section;
	std::string rack;
	
    public:
	TLocation();
	TLocation(std::string section, std::string rack);
	
	void setSection(std::string section);
	void setRack(std::string rack);
	std::string getSection();
	std::string getRack();
	
	void print();
};

#endif /* TLOCATION_H */
