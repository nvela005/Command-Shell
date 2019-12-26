



#include "../header/rmhash.hpp"


TEST(FunctionList, Rmash) {

	std::string y = "";
	std::vector<int>temp(0);
	EXPECT_EQ("", rmhash(y,temp));
	
	y = "ls && mkdir hello # echo \"hello world \"";
	temp = {25,38};
	EXPECT_EQ("ls && mkdir hello", rmhash(y,temp));

	y = "ls && echo \"hello world\"";
	temp = {11,23};
	EXPECT_EQ("ls && echo \"hello world\"", rmhash(y,temp));

	y = "ls || echo \"hello # world\"";
	temp = {11,25};
	EXPECT_EQ("ls || echo \"hello # world\"", rmhash(y,temp));
}
