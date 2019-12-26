



#ifndef _RMQUOTES_HPP_
#define _RMQUOTES_HPP_



#include <string>


std::string rmquotes(std::string x) {

	int y = 0;

	while (x.find("\"", 0) != std::string::npos) {
		
		y = x.find("\"",0);
		x.erase(y,1);
	}
	return x;
}
		 


























#endif
