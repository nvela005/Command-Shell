


#include "../header/greatestint.hpp"


TEST(FunctionList, GreatInt) {

	std::vector<int> temp(0);
	EXPECT_EQ(-2, greatestint(temp, 4));

	temp = {1,3,5,6};
	EXPECT_EQ(1, greatestint(temp,4));

	temp = {3,4,5,6};
	EXPECT_EQ(-2, greatestint(temp,2));

	EXPECT_EQ(3, greatestint(temp,7));
} 
