

#ifndef _VECSTRINGS_HPP_
#define _VECSTRINGS_HPP_

#include <string>
#include <vector>
#include "base.hpp"
#include "andop.hpp"
#include "orop.hpp"
#include "colon.hpp"
#include "rquotes.hpp"
#include "input.hpp"
#include "output.hpp"
#include "output2.hpp"
#include "pipe.hpp"
// searches through the string passed in for
// && , ||, and ;
// for every valid  one found the function appends
// a base pointer to the vector passed in
// separates the string into substrings
// appends them to the vector string passed in

void vecstrings(std::vector<Base*>& x, 
                std::vector<std::string>& y,
                std::vector<int>vecquotes, 
                std::string str) {
    
    for( unsigned int i = 0; i < str.size() - 1; ++i ) {
        
        char char1 = str.at(i);
	char char2 = str.at(i + 1);
	int num1 = greatestint(vecquotes,i);

        if ((( char1 == '&' && char2 == '&') ||
              (char1 == '|' && char2 == '|') ||
	       (char1 == '>' && char2 == '>')) &&
              (num1 % 2 != 0 ||num1 == -2))
		
                {
                    y.push_back(rmquotes(str.substr(0, i - 1)));
                    str = str.substr( i + 3, str.size() - 3);
                    vecquotes = vecquote(str);
                    i = 0;
            	
                    if(char1 == '&') {
                    	x.push_back(new AndOp());
		    }
		    else if ( char1 == '|') {
			x.push_back(new OrOp());
		    }
		    else { x.push_back(new Output2());}
                }
        else if((char1 == '<' || char1 == '>' || char1 == '|')
		 && (num1 % 2 != 0 || num1 == -2)) {
			y.push_back(rmquotes(str.substr(0, i - 1)));
			str = str.substr(i + 2, str.size() - 2);
			vecquotes = vecquote(str);
			i = 0;
			if(char1 == '<') {x.push_back(new Input());}
			else if ( char1 == '|') {x.push_back(new Pipe());}
			else {x.push_back(new Output());}
	}
        else if(char1 == ';'&& (num1 % 2 != 0 || num1 == -2)) {
            
            y.push_back(rmquotes(str.substr(0,i)));
            str = str.substr(i + 2, str.size() - i - 2);
            vecquotes = vecquote(str);
            i = 0;

	    x.push_back(new ScOp());
        }
        
        
    }
    y.push_back(rmquotes(str));
}

#endif
