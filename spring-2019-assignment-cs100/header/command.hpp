

#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_


#include "base.hpp"


class Command: public Base {
    
  private:  
  
  std::string incommand;
  
  public:
    //Command() {return;}
        Command(std::string t) {
              
             incommand = t;
        }
        virtual std::string getcommand() {
                                    
                return incommand;
        }
        virtual int RunCommand();                                           
};


#endif
