#ifndef _PRECEDENCE_HPP_
#define _PRECEDENCE_HPP
#include "base.hpp"
#include "ctree.hpp"
#include <string>
#include "vecquote.hpp"
#include "greatestint.hpp"

using namespace std;

int  ParenthesisExist(string userString) {
    int rightCounter = 0;
    int leftCounter = 0;
    std::vector<int> temp = vecquote(userString);
    int number = 0;
    for (int i = 0; i < userString.size(); i++) {
        number = greatestint(temp, i);
        if (userString.at(i) == '(' && (number == -2 || number % 2 != 0)) {
             rightCounter++;
        }
	else {
            if (userString.at(i) == ')'&& rightCounter > leftCounter && (number == -2 || number % 2 != 0)) {
                leftCounter++;
            }
            else if (userString.at(i) == ')' && rightCounter <= leftCounter && (number == -2 || number % 2 != 0)) {
                return 0;
            }
        }
    }
    if (rightCounter != leftCounter) {
        return 0;
    }
    return 1;
}


#endif

