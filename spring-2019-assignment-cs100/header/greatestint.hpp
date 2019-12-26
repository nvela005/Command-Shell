

#ifndef _GREATESTINT_HPP_
#define _GREATESTINT_HPP_


#include <vector>
int greatestint( std::vector<int> x, int y) {
    
    // returns -2 if x is empty or
    // there no indice that satisfies conditional
    int c = -2;
    for( unsigned int i = 0; i < x.size(); ++i ) {
        
        if( x.at(i) < y) {
            
            c = i;
        }
    }
    return c;
}

#endif
