

#ifndef _ANDOP_HPP_
#define _ANDOP_HPP_

#include "base.hpp"
#include "command.hpp"
class AndOp: public Base {
    
    private:
    Base* leftchain;
    Base* rcommand;
    
    public:
    AndOp() {return;}
    AndOp(Base* x, Base* y) {
        
        leftchain = x;
        rcommand = y;
    }
    
    virtual void addleftop(Base* x) { leftchain = x; }
    virtual void addrightop(Base* x) { rcommand = x; }
    virtual std::string getcommand() {
        
        return leftchain->getcommand() + " -> " + rcommand->getcommand();
    }
    
    virtual int RunCommand() {
	
	if (leftchain->RunCommand() == 0) {
		return rcommand->RunCommand();
	}
	return -1;
    }

};


#endif
