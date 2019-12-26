



#include "../header/base.hpp"
#include "../header/andop.hpp"
#include "../header/colon.hpp"
#include "../header/orop.hpp"
#include "../header/mock1.hpp"
#include "../header/mock2.hpp"


TEST(Operators, MembFunc) {

	Base* temp = new AndOp(new mock1(),new mock1());
	
	EXPECT_EQ("ls -l -> ls -l", temp->getcommand());
	EXPECT_EQ(0, temp->RunCommand());

	Base* temp1 = new OrOp(new mock1(), new mock1());
	EXPECT_EQ(0, temp1->RunCommand());

	Base* temp2 = new AndOp(new mock2(), new mock2());
	EXPECT_EQ(-1, temp2->RunCommand());
	
	Base* temp3 = new OrOp(new mock2(), new mock2());
	EXPECT_EQ(-1, temp3->RunCommand());
	
}	


