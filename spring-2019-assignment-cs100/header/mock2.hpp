



#ifndef _MOCK2_HPP_
#define _MOCK2_HPP_


#include "base.hpp"

class mock2: public Base {

   public:
        mock2() { return;}
        virtual std::string getcommand() {

                return "ls -l";
        }
        virtual int RunCommand() {

                return -1;
        }




};

#endif

