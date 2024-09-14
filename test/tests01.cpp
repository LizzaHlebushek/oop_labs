#include <gtest/gtest.h>
#include "../include/reconf_str.h"

TEST(BasicTest, BasicTest_0) {
    EXPECT_EQ(reconfString("ababc"), "babac");
}

TEST(BasicTest, BasicTest_1) {
    EXPECT_EQ(reconfString("accccacacccbac"), "bccccbcbcccabc");
}

TEST(BasicTest, EmptyStringTest) {
    EXPECT_EQ(reconfString(""), "");
}

TEST(BasicTest, OneCharacterTest_0) {
    EXPECT_EQ(reconfString("b"), "a");
}

TEST(BasicTest, OneCharacterTest_1) {
    EXPECT_EQ(reconfString("a"), "b");
}

TEST(BasicTest, OneCharacterTest_2) {
    EXPECT_EQ(reconfString("c"), "c");
}

//=================InvalidCharacter_Tests=====================================================================================================

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_z) {
    std::string input = "abcz";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character 'z'");
    }
}

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_A) {
    std::string input = "abcA";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character 'A'");
    }
}

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_dot) {
    std::string input = "abc.";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '.'");
    }
}

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_space) {
    std::string input = "abc ";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character ' '");
    }
}

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_ampersand) {
    std::string input = "abc&";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '&'");
    }
}

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_bracket) {
    std::string input = "abc}";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '}'");
    }
}

TEST(InvalidCharacterTests_Death, OneInvalidCharacter_6) {
    std::string input = "abc6";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '6'");
    }
}

TEST(InvalidCharacterTests_Death, InvalidCharacters1) {
    std::string input = "abc}zsusvu;jvn";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '}'");
    }
}

TEST(InvalidCharacterTests_Death, InvalidCharacters2) {
    std::string input = "abc!oivbd}}}{}3##917";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '!'");
    }
}

TEST(InvalidCharacterTests_Death, InvalidCharacters3) {
    std::string input = "abc060982476";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '0'");
    }
}

TEST(InvalidCharacterTests_Death, OnlyInvalidCharacters) {
    std::string input = "{72isvisv!poiuyt65}";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '{'");
    }
}

TEST(InvalidCharacterTests_Death, OnlyOneInvalidCharacter) {
    std::string input = "-";
    try {
        reconfString(input);
        FAIL() << "Expected std::runtime_error was not thrown.";
    } catch (const std::runtime_error& e) {
        std::string mess = e.what();
        EXPECT_EQ(mess, "the string contains an invalid character '-'");
    }
}

//==================================================================================================
// TEST(InvalidCharacterTests, InvalidCharacter_rus) {
//     std::string input = "abcф";
//     try {
//         reconfString(input);
//         FAIL() << "Expected std::runtime_error was not thrown.";
//     } catch (const std::runtime_error& e) {
//         std::string mess = e.what();
//         EXPECT_EQ(mess, "the string contains an invalid character 'ф'");
//     }
// }

// TEST(InvalidCharacterTests, InvalidCharacter_rus1) {
//     std::string input = "фgds";
//     try {
//         reconfString(input);
//         FAIL() << "Expected std::runtime_error was not thrown.";
//     } catch (const std::runtime_error& e) {
//         std::string mess = e.what();
//         EXPECT_EQ(mess, "the string contains an invalid character 'ф'");
//     }
// }

// TEST(InvalidCharacterTests, InvalidCharacter_emoji) {
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