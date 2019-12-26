

#ifndef _MOCK1_HPP_
#define _MOCK1_HPP_


#include "base.hpp"

class mock1: public Base {

   public:	
	mock1() { return;}	
	virtual std::string getcommand() {
		
		return "ls -l";
	}
	virtual int RunCommand() {

		return 0;
	}



	
};








#endif
