

#ifndef _BASE_HPP_
#define _BASE_HPP_



#include<string>

class Base {
   
    private: Base* parent; 
    public:
    
    	Base() { parent = NULL; return; }
    	virtual int RunCommand() = 0;


        virtual void addleftop(Base* x) { return; }
        virtual void addrightop(Base*x) { return; }
	virtual void addrightop(std::string x){ return;}
        virtual std::string getcommand() = 0;
	virtual bool input_output() { return false; }

                    
                        
};



#endif
