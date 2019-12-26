


#include "../header/vecstrings.hpp"



TEST(FunctionList, VecString) {

	std::string str = "ls; mkdir hello && echo \"hello && world\" || ls -l";
	std::vector<int> vecquo = {24, 39};
	std::vector<Base*> temp(0);
	std::vector<std::string> temp1(0);

	std::vector<std::string> expected = {"ls", "mkdir hello", "echo hello && world", "ls -l"};
	
	vecstrings(temp, temp1, vecquo, str);
	EXPECT_EQ(expected, temp1);
	EXPECT_EQ(3, temp.size());

	str = "ls";
	vecquo.clear();
	temp.clear();
	temp1.clear();
	expected = {"ls"};

	vecstrings(temp,temp1,vecquo,str);
	EXPECT_EQ(expected, temp1);
	EXPECT_EQ(0, temp.size());
	
}


// Assignment 4
TEST(FunctionList3, InputOutput) {

	std::string str = "sort < hello.txt > test.txt";
	std::vector<int> vecquo(0);
	std::vector<Base*> temp(0);
	std::vector<std::string> temp1(0);
	
	std::vector<std::string> expected = {"sort", "hello.txt", "test.txt"};
	vecstrings(temp, temp1, vecquo, str);
	EXPECT_EQ(expected, temp1);
	EXPECT_EQ(2, temp.size());
}


TEST(FunctionList3, OutputParenthesis) {

	std::string str = "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2";
	std::vector<int> vecquo(0);
	std::vector<Base*> temp(0);
	std::vector<std::string> temp1(0);

	std::vector<std::string> expected = {"cat", "existingInputFile", "tr A-Z a-z", "tee newOutputFile1", "tr a-z A-Z", "newOutputFile2"};
	vecstrings(temp,temp1,vecquo,str);
	EXPECT_EQ(expected,temp1);
	EXPECT_EQ(5, temp.size());
}
