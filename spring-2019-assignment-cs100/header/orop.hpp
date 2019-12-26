

#ifndef _OROP_HPP_
#define _OROP_HPP_

#include "base.hpp"
#include<string>

class OrOp: public Base {
    
    private:
    Base* leftchain;
    Base* rcommand;
    
    public:
    OrOp() {return;}
    OrOp(Base* x, Base* y) {
        
        leftchain = x;
        rcommand = y;
    }
    
    virtual void addleftop(Base* x) { leftchain = x; }
    virtual void addrightop(Base* x) { rcommand = x; }
    virtual std::string getcommand() {
        
        return leftchain->getcommand() + " -> " + rcommand->getcommand();
    }
    virtual int RunCommand() {

	if( leftchain->RunCommand() == 0) {

		return 0;
	}
	return rcommand->RunCommand();
    } 

};


#endif
