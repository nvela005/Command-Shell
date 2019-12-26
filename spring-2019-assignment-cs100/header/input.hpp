
#ifndef _INPUT_HPP_
#define _INPUT_HPP_



#include "base.hpp"
#include <string>
#include <unistd.h>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class Input: public Base {

	private: 	
		Base* left;
		std::string file_name = "empty";

	public:
		Input() { return; }
		virtual void addleftop(Base* x) { left = x; }
		virtual	void addrightop(std::string file) { file_name = file; }
		virtual std::string getcommand() { return left->getcommand() + " <- " + file_name;} 	
		virtual int RunCommand() {
				 
				int savestdin = dup(0);
				close(0);
				char* cstr = new char[file_name.size()];
				std::strcpy(cstr,file_name.c_str());

				int newfile = open(cstr, O_RDONLY);
				if( newfile == -1) {perror("invald file name"); return -1;}
				dup(newfile);

				 int x = left->RunCommand();close(0); dup(savestdin); return x;
		}
		virtual bool input_output() { return true; }

				


};


#endif
