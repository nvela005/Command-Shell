

#ifndef _CREATEOPERAND_HPP_
#define _CREATEOPERAND_HPP_


#include <string>
#include <vector>
#include <iostream>
#include "base.hpp"
#include "andop.hpp"
#include "orop.hpp"
#include "colon.hpp"
#include "rquotes.hpp"
#include "ctree.hpp"
#include "vecstrings.hpp"
#include "leftparenthesis.hpp"
#include "input.hpp"
#include "output.hpp"
#include "output2.hpp"
#include "pipe.hpp"

void createoperand(std::vector<Base*>& x, std::vector<Base*>& y, std::string& str, int i) {

		std::vector<std::string> temp1(0);
   		std::vector<Base*> temp3(0);
    		std::string j = "";

		 j = rmquotes(str.substr(0, i - 1)); 
               
		 if( j != "") {
                    vecstrings(temp3, temp1, vecquote(j),j);
                    y.push_back(createtree(temp3, temp1));

             
                 }

                 if(str.at(i) == '&') {
                        x.push_back(new AndOp());
                  }
                  else if(str.at(i) == '|'){
                        x.push_back(new OrOp());
                   }
		  else {x.push_back(new Output2());}
		str = str.substr( i + 3, str.size() - 3);

}


void createoperand1(std::vector<Base*>& x, std::vector<Base*> & y, std::string& str, int i ) {
	
	std::vector<std::string> temp1(0);
        std::vector<Base*> temp3(0);
        std::string j = "";

	if(str.at(i) == ';') {	j = rmquotes(str.substr(0,i));}
	else { j = rmquotes(str.substr(0, i - 1));}
               
	 if(j != "") {

           	 vecstrings(temp3,temp1,vecquote(j), j);
            	y.push_back(createtree(temp3, temp1));
          }
           
	   if(str.at(i) == ';') {x.push_back(new ScOp());}
	   else if(str.at(i) == '|') {x.push_back(new Pipe());}
	   else if(str.at(i) == '>') {x.push_back(new Output());}
	   else { x.push_back(new Input());}

	  str = str.substr(i + 2, str.size() - i - 2);


}

void updatevec(std::vector<Base*>& y) {
		
			if(y.size() < 3) {return;}

			y.at(y.size() - 2)->addleftop(y.at(y.size() - 3));
                        if(y.at(y.size() -2)->input_output()) { 
				y.at(y.size() - 2)->addrightop(y.at(y.size() - 1)->getcommand());
			}
			else {
                        	y.at(y.size() - 2)->addrightop(y.at(y.size() - 1));
			}
                        y.at(y.size() - 3) = y.at(y.size() - 2);
                        y.resize(y.size() - 2);
}





























#endif
