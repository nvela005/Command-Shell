#ifndef _OUTPUT_HPP_
#define _OUTPUT_HPP_



#include "base.hpp"
#include <string>
#include <unistd.h>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

class Output: public Base {

        private:
                Base* left;
                std::string file_name = "empty";

        public:
                Output() { return; }
                virtual void addleftop(Base* x) { left = x; }
                virtual void addrightop(std::string file) { file_name = file; }
                virtual std::string getcommand() { return left->getcommand() + " -> " + file_name;}
                virtual int RunCommand() {

                                int savestdout = dup(1);
                                
                                char* cstr = new char[file_name.size()];
                                std::strcpy(cstr,file_name.c_str());

                                int newfile = open(cstr, O_WRONLY|O_TRUNC);
				if(newfile == -1) { perror("file descriptor error"); return -1;}
				close(1);
                                dup(newfile);
                                int x = left->RunCommand();
				close(1);dup(savestdout);
			return x;
                }
                virtual bool input_output() { return true; }




};


#endif
        
