


#include <iostream>
#include<string>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream> 
#include <unistd.h> 
#include <vector>
#include <cstring>
#include <stdlib.h>
#include "../header/command.hpp"
#include "../header/testcom.hpp"



int Command::RunCommand() {
    
    
    
     std::string arg = incommand;


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
        
	char ex[] = "exit\0";
	char tcom[] = "test";
	char bcom[] = "[";

	if(strcmp(ex,argt[0]) == 0) {

                        exit(0);
        }
	
	if(strcmp(tcom, argt[0]) == 0 ||
                        strcmp(bcom, argt[0]) == 0)
             						{
                        if(testcommand(argt)) {return 0;}
                        else {return -1;}
        }


        pid_t pid = fork();
        int status;

        if ( pid < 0) {

                perror( "fork() error");
                return -1;  
        }

        else if ( pid == 0 ) {

                execvp(argt[0],argt);
                perror( "execvp error");
                exit(-1);
        }
        else {
            
           if (waitpid(pid, &status, 0) < 0) {
               perror( "waitpid error");
               return -1;
           }
           else if(status != 0) {
               return -1;
           }
		 
         
        }   
    return 0;
}        

       
      


     

    

   

  

 







        










