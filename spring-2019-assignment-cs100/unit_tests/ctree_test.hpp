



#include "../header/greatestint.hpp"
#include "../header/rmhash.hpp"
#include "../header/vecquote.hpp"
#include "../header/vecstrings.hpp"
#include "../header/ctree.hpp"


// this is an integration test using the five functions from above

TEST(InteTest, ComTree) {

	std::string x = "ls; mkdir math && cd cs || echo \"hello ;# World\" # I am a math major";
	std::vector<int> quotes = vecquote(x);
	x = rmhash(x,quotes);
		
	quotes = vecquote(x);
	std::vector<Base*> cotree(0);
	std::vector<std::string> incom(0);

	vecstrings(cotree,incom, quotes, x);
 
        Base* tree = createtree(cotree, incom);
	std::string y = "ls -> mkdir math -> cd cs -> echo hello ;# World";
	EXPECT_EQ(y, tree->getcommand());
}

TEST(IneTest, InputOutput) {
	
	std::string x = "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2";
	std::vector<int>quotes = vecquote(x);
	x = rmhash(x, quotes);

	quotes = vecquote(x);
	std::vector<Base*> cotree(0);
	std::vector<std::string> incom(0);

	vecstrings(cotree, incom, quotes,x);

	Base* tree = createtree(cotree, incom);
	std::string y = "cat <- existingInputFile <-> tr A-Z a-z <-> tee newOutputFile1 <-> tr a-z A-Z -> newOutputFile2";	
	EXPECT_EQ(y, tree->getcommand());

}









