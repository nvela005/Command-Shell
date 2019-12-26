

#ifndef _COLON_HPP_
#define _COLON_HPP_


#include "base.hpp"

class ScOp: public Base {
    
    private:
    Base* leftchain;
    Base* rcommand;
    
    public:
    ScOp() {return;}
    ScOp(Base* x, Base* y) {
        
        leftchain = x;
        rcommand = y;
    }
    
    virtual void addleftop(Base* x) { leftchain = x; }
    virtual void addrightop(Base* x) { rcommand = x; }
    virtual std::string getcommand() {
        
        return leftchain->getcommand() + " -> " + rcommand->getcommand();
    }
    virtual int RunCommand() {

	leftchain->RunCommand();
	return rcommand->RunCommand();
    }

};


#endif
