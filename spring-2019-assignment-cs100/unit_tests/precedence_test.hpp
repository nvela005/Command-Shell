#include "../header/precedence.hpp"

TEST(String, ParentheseTest) {

    std::string x = "((hello))(";
    EXPECT_EQ(0, ParenthesisExist(x));

}

TEST(String, ParenthesesTest2) {

    std::string x = "(hello)";
    EXPECT_EQ(1, ParenthesisExist(x));


}


