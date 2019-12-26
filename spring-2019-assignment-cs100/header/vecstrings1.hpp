


#ifndef _VECSTRINGS1_HPP_
#define _VECSTRINGS1_HPP_




#include<iostream>
#include <string>
#include <vector>
#include "base.hpp"
#include "andop.hpp"
#include "orop.hpp"
#include "colon.hpp"
#include "rquotes.hpp"
#include "ctree.hpp"
#include "vecstrings.hpp"
#include "leftparenthesis.hpp"
#include "createoperand.hpp"
// searches through the string passed in for
// // && , ||, and ;
// // for every valid  one found the function appends
// // a base pointer to the vector passed in
// // separates the string into substrings
// // appends them to the vector string passed in


void vecstrings(std::vector<Base*>& x,
                std::vector<Base*>& y,
                std::vector<int>vecquotes,
                std::string str) {
std::vector<Base*>temp3 (0); std::vector<std::string> temp1 (0); std::string j;
  	char char1;
	char char2;
	int num1;
    for( unsigned int i = 0; i < str.size(); ++i ) {

        char1 = str.at(i);
        if(i != str.size() - 1){ char2 = str.at(i + 1);}
        num1 = greatestint(vecquotes,i);

        if ((( char1 == '&' && char2 == '&') ||
              (char1 == '|' && char2 == '|') ||
		(char1 == '>' && char2 == '>')) &&
              (num1 % 2 != 0 ||num1 == -2))
		{
		
		createoperand(x,y,str, i);
           	vecquotes = vecquote(str);
                i = 0;	     
                }
	else if(char1 == '|' || char1 == '>' || char1 == '<') { 
		
		createoperand1(x,y,str,i);
		vecquotes = vecquote(str);
		i = 0;
	}
        else if(char1 == ';'&& (num1 % 2 != 0 || num1 == -2)) {
		
		createoperand1(x,y,str,i);
		vecquotes = vecquote(str);
		i = 0;
        }
	num1 = greatestint(vecquotes,i);
	if(str.at(i) == '(' && (num1 % 2 != 0 || num1 == -2)) {
		int indexleft = leftparenth(str, i);
		std::string r = str.substr(i + 1, indexleft - i - 1);

		if ( r.find("(", 0) != std::string::npos) {
			vecstrings(y,y,vecquote(r), r); updatevec(y);
			if(indexleft != str.size() - 1) {str = str.substr(indexleft + 1, str.size() - indexleft - 1); i = -1;}
			else{ str.clear();i = 0;}
		}
		else {str.erase(i,1); str.erase(indexleft - 1, 1);
			
			i = indexleft - 2;
		}
	
    	}
	}
  if(str != "") { 
	j =  rmquotes(str);
   	vecstrings(temp3,temp1,vecquote(j), j);
   	y.push_back(createtree(temp3,temp1));
  }
}



#endif
