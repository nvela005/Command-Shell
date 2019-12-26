


#include "../header/vecstrings1.hpp"
#include "../header/createoperand.hpp"
#include "../header/ctree.hpp"






TEST(PCTREE, INPUTOUTPUT) {



	std::string command = "((test -e head && test -e header) | sort) > file_name";
	std::vector<Base*> mainoperators(0);
	std::vector<Base*> lessoperators(0);
	std::vector<int> indexquo = vecquote(command);

	vecstrings(mainoperators, lessoperators, indexquo, command);
	
	EXPECT_EQ(2, lessoperators.size());
	std::string expected = "test -e head -> test -e header <-> sort -> file_name";
	Base* tree = createtree(mainoperators,lessoperators);
	EXPECT_EQ(expected, tree->getcommand());
}
