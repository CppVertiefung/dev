#include <iostream>

using namespace std;

#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>


int main()
{
	string line [4] = {"   <LibraryPool>", " <Name>Buechereiverbund Berlin</Name>", "   <Person>", "   <Name>Egon Mustermann</Name>"};
	string tag;
	int value;
	int start;
	int end;
	int len;

	for(unsigned int i = 0; i < 4; i++){
    if (line[i].find("/") != std::string::npos){
        start = line[i].find(">") + 1;
        end = line[i].find("</");
        len = end - start;
        tag = line[i].substr(start, len);
    }else{
        start = line[i].find("<") + 1;
        end = line[i].find(">");
        len = end - start;
        tag = line[i].substr(start, len);
    }
	   cout << tag << endl;
	}


   return 0;
}

