

#include "../header/leftparenthesis.hpp"



TEST(FunctionList2, Parenthesis) {

	std::string x = "(hello world)";
	EXPECT_EQ(12, leftparenth(x, 0));
	
	x = "hello world";
	EXPECT_EQ(-1, leftparenth(x,0));

	x = "ls || (ls || (echo A && echo B))";
	EXPECT_EQ(31 ,leftparenth(x,6));

	x = "(ls || echo \"hi )( world\")";
	EXPECT_EQ(x.size() - 1, leftparenth(x,0));
}
