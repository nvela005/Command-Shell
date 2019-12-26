




#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cstring>

int main() {



	std::string arg = "cd math";


	char * cstr = new char [arg.length()+1];
  	std::strcpy(cstr, arg.c_str());
	
	char *p = std::strtok(cstr, " ");
	
	
	std::vector< std::vector<char*> >argv;
	std::vector<char*> temp;
	
	
  	while (p != NULL ) {

		temp.push_back(p);
		
		p = std::strtok(NULL, " ");
	
	}

	argv.push_back(temp);
	char* argt[argv.at(0).size() + 1];
			
	
	for(unsigned int i = 0; i < argv.at(0).size(); ++i) {

		argt[i] = argv.at(0).at(i);
		
	}
	argt[argv.at(0).size()] = NULL;	
	
	pid_t pid = fork();
	
	if ( pid < 0) {

		perror( "fork() error");
		return -1;
	}

	else if ( pid == 0) {
		execvp(argt[0],argt);
		std::cout << "execvp error";
		return -1;
	}
	else {
	       if (waitpid(pid, 0, 0) < 0 ) {
			perror("error waitpid()");
			return -1;
		}
		std::cout << "I'm the parent" << std::endl;
	}
	
	return 0;
}
