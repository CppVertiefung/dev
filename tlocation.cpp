/* 
 * File:   tlocation.cpp
 * Author: phil
 *
 * Created on 26. April 2017, 00:05
 */

#include "tlocation.h"
 
TLocation::TLocation()
{
	setSection("Buero");
	setRack("Fach zum Einsortieren");
}

TLocation::TLocation(std::string section, std::string rack)
{
	setSection(section);
	setRack(rack);
}	

void TLocation::setSection(std::string section)
{
	this->section = section;
}

void TLocation::setRack(std::string rack)
{
	this->rack = rack;
}

std::string TLocation::getSection()
{
	return section;
}

std::string TLocation::getRack()
{
	return rack;
}

void TLocation::print()
{
	printf("Abt.: %s; Regal: %s", section, rack);
}
