#include <gtest/gtest.h>
#include "../include/reconf_str.h"

TEST(ReconfStringTest, BasicTest_0) {
    EXPECT_EQ(reconfString("ababc"), "babac");
}

TEST(ReconfStringTest, BasicTest_1) {
    EXPECT_EQ(reconfString("accccacacccbac"), "bccccbcbcccabc");
}

TEST(ReconfStringTest, EmptyStringTest) {
    EXPECT_EQ(reconfString(""), "");
}

TEST(ReconfStringTest, OneCharacterTest_0) {
    EXPECT_EQ(reconfString("b"), "a");
}

TEST(ReconfStringTest, OneCharacterTest_1) {
    EXPECT_EQ(reconfString("c"), "c");
}

//=================InvalidCharacter_Tests=====================================================================================================

TEST(ReconfStringTest, InvalidCharacter_0) {
    std::string input = "abcz";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character 'z'");
    }
}

TEST(ReconfStringTest, InvalidCharacter_1) {
    std::string input = "abcA";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character 'A'");
    }
}
//==================================================================================================
// TEST(ReconfStringTest, InvalidCharacter_2) {
//     std::string input = "abcф";
//     try {
//         reconfString(input);
//         FAIL() << "Expected std::runtime_error was not thrown.";
//     } catch (const std::runtime_error& e) {
//         std::string mess = e.what();
//         EXPECT_EQ(mess, "the string contains an invalid character 'ф'");
//     }
// }

// TEST(ReconfStringTest, InvalidCharacter_3) {
//     std::string input = "фgds";
//     try {
//         reconfString(input);
//         FAIL() << "Expected std::runtime_error was not thrown.";
//     } catch (const std::runtime_error& e) {
//         std::string mess = e.what();
//         EXPECT_EQ(mess, "the string contains an invalid character 'ф'");
//     }
// }

// TEST(ReconfStringTest, InvalidCharacter_4) {
//     std::string input = "abc😎";
//     try {
//         reconfString(input);
//         FAIL() << "Expected std::runtime_error was not thrown.";
//     } catch (const std::runtime_error& e) {
//         std::string mess = e.what();
//         EXPECT_EQ(mess, "the string contains an invalid character '😎'");
//     }
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}