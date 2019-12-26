



#ifndef _PIPE_HPP_
#define _PIPE_HPP_



#include "base.hpp"
#include <string>
#include <unistd.h>
#include <cstring>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

class Pipe: public Base {

        private:
                Base* left;
                std::string right = "empty";

        public:
                Pipe() { return; }
                virtual void addleftop(Base* x) { left = x; }
                virtual void addrightop(std::string y) { right = y; }
                virtual std::string getcommand() { return left->getcommand() + " <-> " + right;}
                virtual int RunCommand() {

			int fds[2];pipe(fds);
			int status;
			pid_t pid = fork();

			if( pid == 0) { close(1); dup(fds[1]); left->RunCommand(); exit(0); }
			else { waitpid(pid,&status,0);}
 
			std::string arg = right;
        		char * cstr = new char [arg.length()+1];
       			std::strcpy(cstr, arg.c_str());
        		char *p = std::strtok(cstr, " ");
        		std::vector<char*> temp;

        		while (p != NULL ) {

                		temp.push_back(p);

                		p = std::strtok(NULL, " ");

        		}	
        		char* argt[temp.size() + 1];
        		for(unsigned int i = 0; i < temp.size(); ++i) {

                		argt[i] = temp.at(i);
        		}	
        		argt[temp.size()] = NULL;
			close(fds[1]);
			close(0);
			dup(fds[0]);

			pid = fork();
			if( pid == 0) {execvp(argt[0],argt); perror("execvp error"); exit(-1);}
			else { waitpid(pid,&status, 0); if(status != 0) { return -1;} }

			return 0;
			
				
        	}
        virtual bool input_output() { return true;}




};


#endif

