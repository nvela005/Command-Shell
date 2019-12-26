

#ifndef _LEFTPARENTHESIS_HPP_
#define _LEFTPARENTHESIS_HPP_

#include <string>
#include <vector>
#include "vecquote.hpp"
#include "greatestint.hpp"
int leftparenth(std::string temp, int x) {


	int i = 0;
	int j = 0;
	std::vector<int> temp1 = vecquote(temp);
	int num;
	for( int z = x + 1; z < temp.size(); ++z) {
		num = greatestint(temp1, z);
		if(temp.at(z) == '(' && (num == -2 || num % 2 != 0)) { i = i + 1;}
		else if(temp.at(z) == ')' && i != j && (num == -2 || num % 2 != 0)) { j = j + 1;}
		else if(temp.at(z) == ')' && i == j && (num == -2 || num % 2 != 0)) { return z;}
	}

	return -1;
}




























#endif
