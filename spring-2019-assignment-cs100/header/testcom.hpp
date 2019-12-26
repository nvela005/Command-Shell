





#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <cstring>

bool testcommand(char* hello[]) {
    
    char fflag[] = "-f";
    char dflag[] = "-d";
    char eflag[] = "-e";
    
    struct stat buf;
    int x;
    int y = 0;
    
    if ( strcmp(hello[1], fflag) == 0)  {
        x = stat(hello[2],&buf);
        if( x == 0 && S_ISREG(buf.st_mode)) { 
            y = 1;
        }
    }
    else if ( strcmp(hello[1], dflag) == 0) {
        x = stat(hello[2],&buf);
        if( x == 0 && S_ISDIR(buf.st_mode)) { 
            y = 1;
        }
    }
    else if (strcmp(hello[1], eflag ) == 0) {
        x = stat(hello[2],&buf);
        if ( x == 0) {
            y = 1;
        }
    }
    else {
        x = stat(hello[1],&buf);
        if ( x == 0) {
            y = 1;
        }
    }
    if ( y == 1) {
        std::cout << "(True)" << std::endl;
        return true;
    }
        std::cout << "(False)" << std::endl;
    return false;
}
