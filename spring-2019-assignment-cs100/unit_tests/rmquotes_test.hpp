


#include "../header/rquotes.hpp"




TEST(FunctionList, Rmquotes) {



	std::string x = "hello world";
	
	EXPECT_EQ("hello world", rmquotes(x));

	x = "hello \" world \"";
	EXPECT_EQ("hello  world ", rmquotes(x));
}
