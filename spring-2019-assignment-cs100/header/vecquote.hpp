



#ifndef _VECQUOTE_HPP_
#define _VECQUOTE_HPP_


// vecquote returns a vector of integers that hold
// the indices of each quote character in the string passed in

#include <string>
#include <vector>
std::vector<int> vecquote( std::string x) {

	std::vector<int> indices(0);

	for( unsigned int i = 0; i < x.size(); ++i) {

		if( x.at(i) == '\"') {

			indices.push_back(i);
		}
	}
	
	return indices;
}






#endif
