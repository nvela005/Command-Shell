


#include "../header/vecquote.hpp"


TEST(FunctionLists, Vecquote) {


	std::string x = "";
	EXPECT_EQ(0, vecquote(x).size());

	x = "\" Hello world \" is not correct \"";

	std::vector<int> temp = {0, 14,31};
	EXPECT_EQ(temp, vecquote(x));

	x = "Mathematics and Computer Science are great";
	EXPECT_EQ(0, vecquote(x).size());
}
