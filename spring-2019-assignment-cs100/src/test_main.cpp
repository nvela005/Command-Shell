



#include "gtest/gtest.h"
#include "../unit_tests/vecquote_test.hpp"
#include "../unit_tests/great_test.hpp"
#include "../unit_tests/vecstr_test.hpp"
#include "../unit_tests/rmhash_test.hpp"
#include "../unit_tests/ctree_test.hpp"
#include "../unit_tests/memfunc_test.hpp"
#include "../unit_tests/rmquotes_test.hpp"
#include "../unit_tests/precedence_test.hpp"
//assignment 3 test cases
#include "../unit_tests/leftparent_test.hpp"
#include "../unit_tests/vec2string_test.hpp"
#include "../unit_tests/modvec_test.hpp"

//assignment 4 testcases
//additional test cases in vec2string_test 
// and in vecstr_test.hpp
#include "../unit_tests/createop.hpp"

int main( int argc, char **argv) {

	::testing::InitGoogleTest(&argc,argv);
	
	return RUN_ALL_TESTS();
}
