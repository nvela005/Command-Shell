

#ifndef _RMHASH_HPP_
#define  _RMHASH_HPP_

#include <string>
#include <vector>
#include "greatestint.hpp"

std::string rmhash(std::string x, std::vector<int> quotes) {

	
	
	for(unsigned int i = 0; i < x.size(); ++i) {

		int c = greatestint(quotes,i); 


		if(x.at(i) == '#' &&
		   (c == -2 || c % 2 != 0) ) {
                
		 
			x = x.substr(0,i);
			if ( x == "") {
				return x;
			}
	                while ( x.size() != 0) {

              			if (x.at(x.size() - 1) == ' ') {
					x.resize(x.size() - 1);
				}
				else {
					return x;
				}
			}
			return x;
			
		}
	}
	
	return x;

}



















#endif 
