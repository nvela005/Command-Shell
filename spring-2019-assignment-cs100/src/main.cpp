


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "../header/andop.hpp"
#include "../header/orop.hpp"
#include "../header/colon.hpp"
#include "../header/command.hpp"
#include "../header/base.hpp"
#include "../header/ctree.hpp"
#include "../header/greatestint.hpp"
#include "../header/rmhash.hpp"
#include "../header/vecquote.hpp"
#include "../header/vecstrings.hpp"
#include "../header/precedence.hpp"
#include "../header/vecstrings1.hpp"
#include "../header/input.hpp"

int main() {

	std::string command = "";
	
	while(command == "") {
	        
		std::cout << " rshell >> ";
		getline(std::cin, command);

	}
        if (ParenthesisExist(command) == 0) {
            perror("Parentheses in the wrong place");
             return 0;
        }	

	std::vector<int>quo = vecquote(command);
        command = rmhash(command,quo);

	if(command == "") {
		return 0;
	}

	quo = vecquote(command);
	std::vector<Base*> operators(0);
	std::vector<std::string> commands(0);

	if( command.find("(", 0) == std::string::npos) {
		vecstrings(operators,commands,quo,command);
		Base* comtree = createtree(operators, commands);
		comtree->RunCommand();
	}

	else {
		std::vector<Base*> operator1(0);
		vecstrings(operators,operator1,quo, command);
		Base* comtree = createtree(operators, operator1);
		comtree->RunCommand();
	}




	return 0;
}
