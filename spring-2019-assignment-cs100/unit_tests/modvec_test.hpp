

#include "../header/createoperand.hpp"


TEST(Update_Vec_Base, ModifyVec) {

	std::vector<Base*> temp2(0);

	temp2.push_back(new Command("ls"));
	temp2.push_back(new AndOp());
	temp2.push_back(new Command("echo A"));
	
	updatevec(temp2);
	EXPECT_EQ(1, temp2.size());
	EXPECT_EQ("ls -> echo A", temp2.at(0)->getcommand());

	temp2.clear();
	updatevec(temp2);
	EXPECT_EQ(0, temp2.size());
}

TEST(Update_Vec_Base, CreateOp) {

	std::vector<Base*> temp1(0);
	std::vector<Base*> temp2(0);

	std::string x = "ls && echo A || echo D; echo B";
	
	createoperand(temp1, temp2, x, 3);
	EXPECT_EQ("echo A || echo D; echo B", x);
	EXPECT_EQ(1, temp1.size());
	EXPECT_EQ(1, temp2.size());
}

TEST(Update_Vec_Base, CreatOp1) {

	std::vector<Base*> temp1(0);
	std::vector<Base*> temp2(0);

	std::string x = "ls; echo A || echo D";
	createoperand1(temp1, temp2, x,2);

	EXPECT_EQ("echo A || echo D", x);
	EXPECT_EQ(1,temp1.size());
	EXPECT_EQ(1,temp2.size());
}
