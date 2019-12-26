


#include "../header/vecstrings1.hpp"




TEST(FunctionList2, VecStrings1) {


	std::string x = "ls || (ls && (echo A || echo B))";
	std::vector<Base*> temp1(0);
	std::vector<Base*> temp2(0);
	
	vecstrings(temp1,temp2,vecquote(x), x);
	EXPECT_EQ(2, temp2.size());
	
	EXPECT_EQ("ls", temp2.at(0)->getcommand());
	EXPECT_EQ("ls -> echo A -> echo B", temp2.at(1)->getcommand());
	
}
TEST(FunctionList2, VecStrings2) {

	std::string x = "(ls && (echo A || echo B)) || ls";
	std::vector<Base*> temp1(0);
	std::vector<Base*> temp2(0);

	vecstrings(temp1,temp2, vecquote(x), x);
	EXPECT_EQ(2, temp2.size());

}
TEST(FunctionList2, VecStrings3) {

	std::string x = "((ls && (echo A || echo B)); echo D); echo C";
	std::vector<Base*> temp1(0);
	std::vector<Base*> temp2(0);

	vecstrings(temp1,temp2, vecquote(x),x);

	EXPECT_EQ(2, temp2.size());
	EXPECT_EQ(1, temp1.size());

	
}
TEST(FunctionList2, VecStrings4) {

	std::string x = "(ls && echo A) || (echo C || echo D); (mkdir cs || echo F)";
	std::vector<Base*> temp1(0);
	std::vector<Base*> temp2(0);
	
	vecstrings(temp1,temp2, vecquote(x), x);

	EXPECT_EQ(3, temp2.size());
	EXPECT_EQ(2, temp1.size());

}
//assignment4

TEST(InputOutput, InputOutput){


	std::string x = "(ls && echo A) > file_name";
        std::vector<Base*> temp1(0);
        std::vector<Base*> temp2(0);

        vecstrings(temp1,temp2, vecquote(x), x);

        EXPECT_EQ(1, temp1.size());
        EXPECT_EQ(2, temp2.size());
	EXPECT_TRUE(temp1.at(0)->input_output());
	EXPECT_EQ("ls -> echo A", temp2.at(0)->getcommand());
	EXPECT_EQ("file_name", temp2.at(1)->getcommand());
}
TEST(InOut, NestedParen){


        std::string x = "((ls && echo A) >> file_name) && test -e header";
        std::vector<Base*> temp1(0);
        std::vector<Base*> temp2(0);

        vecstrings(temp1,temp2, vecquote(x), x);

        EXPECT_EQ(1, temp1.size());
        EXPECT_EQ(2, temp2.size());
        EXPECT_EQ("ls -> echo A <- file_name", temp2.at(0)->getcommand());
        EXPECT_EQ("test -e header", temp2.at(1)->getcommand());
}























