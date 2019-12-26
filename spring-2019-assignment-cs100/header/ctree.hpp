
#ifndef _CTREE_HPP_
#define _CTREE_HPP_

#include "base.hpp"
#include "andop.hpp"
#include "orop.hpp"
#include "colon.hpp"
#include "command.hpp"
#include "input.hpp"
#include <iostream>
Base* createtree(std::vector<Base*>& x, std::vector<std::string> holder) {
    
    if ( x.empty()) {
        
        return new Command(holder.at(0));
    }
    
     x.at(0)->addleftop( new Command(holder.at(0)));
	if(x.at(0)->input_output()) { x.at(0)->addrightop(holder.at(1));}
	else {
     		x.at(0)->addrightop( new Command(holder.at(1)));
	}
     
     for( unsigned int i = 1; i < x.size(); ++i) {
         
        x.at(i)->addleftop(x.at(i - 1));
	if(x.at(i)->input_output()) { x.at(i)->addrightop(holder.at(i + 1)); }
	else {
         x.at(i)->addrightop(new Command(holder.at( i + 1)));
	}
     }
    return x.at(x.size() - 1);
}

Base* createtree(std::vector<Base*>& x, std::vector<Base*> operands) {

	if(x.empty()) { return operands.at(0);}	
	x.at(0)->addleftop(operands.at(0));

	if(x.at(0)->input_output()) {x.at(0)->addrightop(operands.at(1)->getcommand());}
	else {x.at(0)->addrightop(operands.at(1));}

	for( unsigned int i = 1; i < x.size(); ++i) {
		x.at(i)->addleftop(x.at(i - 1));
		if(x.at(i)->input_output()) { x.at(i)->addrightop(operands.at(i+1)->getcommand());}
		else{x.at(i)->addrightop(operands.at(i + 1));}
	}
	return x.at(x.size() - 1);
}

#endif
