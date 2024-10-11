#include <gtest/gtest.h>
#include "five.h"

TEST(Constructor_Tests, Default_Constructor)
{
    Five t;
    std::string s = t.toStr();
    EXPECT_EQ(s, "0");
}

TEST(Constructor_Tests, Char_Constructor0)
{
    Five t ('0');
    std::string s = t.toStr();
    EXPECT_EQ(s, "0");
}

TEST(Constructor_Tests, Char_Constructor4)
{
    Five t ('4');
    std::string s = t.toStr();
    EXPECT_EQ(s, "4");
}

TEST(Constructor_Tests, Int_Constructor0)
{
    Five t (0);
    std::string s = t.toStr();
    EXPECT_EQ(s, "0");
}

TEST(Constructor_Tests, Int_Constructor4)
{
    Five t (4);
    std::string s = t.toStr();
    EXPECT_EQ(s, "4");
}

TEST(Constructor_Tests, Int_Constructor5)
{
    Five t (5);
    std::string s = t.toStr();
    EXPECT_EQ(s, "10");
}

TEST(Constructor_Tests, Int_Constructor15)
{
    Five t (15);
    std::string s = t.toStr();
    EXPECT_EQ(s, "30");
}

TEST(Constructor_Tests, Int_Constructor_Big_Number)
{
    Five t (746536183);
    std::string s = t.toStr();
    EXPECT_EQ(s, "3012103124213");
}

TEST(Constructor_Tests, List_Leading_Zeros) {
    Five five({0, 0, 1, 2, 3});
    EXPECT_EQ(five.size(), 3);
    EXPECT_EQ(five.toStr(), "123");
}

TEST(Constructor_Tests, List_Constructor_1234) {
    Five five({1, 2, 3, 4});
    EXPECT_EQ(five.size(), 4);
    EXPECT_EQ(five.toStr(), "1234");
}

TEST(Constructor_Tests, List_Only_Zeros) {
    Five five({0, 0, 0});
    EXPECT_EQ(five.size(), 1);
    EXPECT_EQ(five.toStr(), "0");
}

TEST(Constructor_Tests, String_Constructor_0)
{
    Five t {"0"};
    std::string s = t.toStr();
    EXPECT_EQ(s, "0");
}

TEST(Constructor_Tests, String_Leading_Zeros) {
    Five t("000123");
    std::string s = t.toStr();
    EXPECT_EQ(s, "123");  
}

TEST(Constructor_Tests, String_All_Zeros) {
    Five t("0000");
    std::string s = t.toStr();
    EXPECT_EQ(s, "0"); 
}

TEST(Constructor_Tests, Empty_String) {
    EXPECT_THROW(Five t(""), std::invalid_argument);
}


TEST(Constructor_Tests, String_Constructor_3)
{
    Five t {"3"};
    std::string s = t.toStr();
    EXPECT_EQ(s, "3");
}

TEST(Constructor_Tests, String_Constructor_44)
{
    Five t {"44"};
    std::string s = t.toStr();
    EXPECT_EQ(s, "44");
}

TEST(Constructor_Tests, String_Constructor_Big_Number)
{
    Five t {"4132032410"};
    std::string s = t.toStr();
    EXPECT_EQ(s, "4132032410");
}

TEST(Constructor_Tests, Copy_Constructor_0)
{
    Five original(0);
    Five copy(original); 
    std::string original_str = original.toStr();
    std::string copy_str = copy.toStr();
    EXPECT_EQ(original_str, "0");
    EXPECT_EQ(copy_str, "0");
    EXPECT_NE(&original, &copy);
}

TEST(Constructor_Tests, Copy_Constructor_12345)
{
    Five original(12345);
    Five copy(original); 
    std::string original_str = original.toStr();
    std::string copy_str = copy.toStr();
    EXPECT_EQ(original_str, "343340");
    EXPECT_EQ(copy_str, "343340");
    EXPECT_NE(&original, &copy);
}

TEST(Constructor_Tests, Move_Constructor_0)
{
    Five original(0);
    std::string original_str = original.toStr();
    Five moved(std::move(original));
    std::string moved_str = moved.toStr();
    EXPECT_EQ(moved_str, original_str);
    EXPECT_EQ(moved_str, "0");
    std::string original_after_move_str = original.toStr();
    EXPECT_TRUE(original_after_move_str.empty());
}

TEST(Constructor_Tests, Move_Constructor_12345)
{
    Five original(12345);
    std::string original_str = original.toStr();
    Five moved(std::move(original));
    std::string moved_str = moved.toStr();
    EXPECT_EQ(moved_str, original_str);
    EXPECT_EQ(moved_str, "343340");
    std::string original_after_move_str = original.toStr();
    EXPECT_TRUE(original_after_move_str.empty());
}

TEST(Size_Tests, Default_Constructor_Size) {
    Five t;
    EXPECT_EQ(t.size(), 1); 
}

TEST(Size_Tests, Int_25_Size) {
    Five t(25);  
    EXPECT_EQ(t.size(), 3);  
}

TEST(Size_Tests, String_3201_Size) {
    Five t("3201"); 
    EXPECT_EQ(t.size(), 4);  
}

TEST(ToStr_Tests, Default_Constructor_ToStr) {
    Five t;
    EXPECT_EQ(t.toStr(), "0");  
}

TEST(ToStr_Tests, Int_25_ToStr) {
    Five t(25);  
    EXPECT_EQ(t.toStr(), "100");  
}

TEST(ToStr_Tests, String_3201_ToStr) {
    Five t("3201");  
    EXPECT_EQ(t.toStr(), "3201"); 
}


TEST(Equals_Tests, Equals_Same_Number) {
    Five t1(25);  
    Five t2(25);  
    EXPECT_TRUE(t1.equals(t2));  
}

TEST(Equals_Tests, Equals_Different_Number) {
    Five t1(25);  
    Five t2(30); 
    EXPECT_FALSE(t1.equals(t2));  
}

TEST(Equals_Tests, Equals_Different_Size_Same_Value) {
    Five t1("000123");  
    Five t2("123");
    EXPECT_TRUE(t1.equals(t2));
}

TEST(Equals_Tests, Equals_DifferentConstructors) {
    Five five1("123");
    Five five2(123);
    EXPECT_FALSE(five1.equals(five2));
}

TEST(Equals_Tests, Equals_SameNumberDifferentConstructors) {
    Five five1("0");
    Five five2(0);
    Five five3('0');
    EXPECT_TRUE(five1.equals(five2));
    EXPECT_TRUE(five1.equals(five3));
    EXPECT_TRUE(five3.equals(five2));
}

TEST(Equals_Tests, Equals_LeadingZeros) {
    Five five1("00123");
    Five five2("123");
    EXPECT_TRUE(five1.equals(five2));
}

TEST(Equals_Tests, Equals_DifferentValues) {
    Five five1("123");
    Five five2("234");
    EXPECT_FALSE(five1.equals(five2));
}

TEST(More_Tests, More_Same_Size_Different_Values) {
    Five five1("123"); 
    Five five2("234"); 
    EXPECT_TRUE(five2.more(five1)); 
    EXPECT_FALSE(five1.more(five2)); 
}

TEST(More_Tests, More_Different_Sizes) {
    Five five1("123"); 
    Five five2("1000"); 
    EXPECT_TRUE(five2.more(five1)); 
    EXPECT_FALSE(five1.more(five2));
}

TEST(More_Tests, More_Equal_Numbers) {
    Five five1("123"); 
    Five five2("123"); 
    EXPECT_FALSE(five1.more(five2)); 
    EXPECT_FALSE(five2.more(five1)); 
}

TEST(More_Tests, More_Zero_Cases) {
    Five five1("0");
    Five five2("123");
    EXPECT_FALSE(five1.more(five2));
    EXPECT_TRUE(five2.more(five1)); 
}

TEST(More_Tests, More_Leading_Zeros) {
    Five five1("00123"); 
    Five five2("123");
    EXPECT_FALSE(five2.more(five1)); 
    EXPECT_FALSE(five1.more(five2)); 
}

TEST(Less_Tests, Less_True_Cases) {
    Five five1("123");
    Five five2("234");
    Five five3("0000");
    
    EXPECT_TRUE(five1.less(five2));
    EXPECT_TRUE(five3.less(five1));
}

TEST(Less_Tests, Less_False_Cases) {
    Five five1("234");
    Five five2("123");
    Five five3("0");
    Five five4("0000");

    EXPECT_FALSE(five1.less(five2));
    EXPECT_FALSE(five2.less(five2));
    EXPECT_FALSE(five3.less(five4));
}

TEST(Less_Tests, Less_Equal_Size_Different_Values) {
    Five five1("01234");
    Five five2("12340");

    EXPECT_TRUE(five1.less(five2));
    EXPECT_FALSE(five2.less(five1));
}

TEST(Less_Tests, Less_Leading_Zeros) {
    Five five1("00000000000000000123");
    Five five2("0123");

    EXPECT_FALSE(five1.less(five2));
    EXPECT_FALSE(five2.less(five1));
}

TEST(Sum_Tests, Simple_Sum) {
    Five five1("123");
    Five five2("432"); 
    Five result = five1.sum(five2);
    EXPECT_EQ(result.toStr(), "1110");  
}

TEST(Sum_Tests, Sum_With_Leading_Zeros) {
    Five five1("000123");
    Five five2("000432");
    Five result = five1.sum(five2);
    EXPECT_EQ(result.toStr(), "1110"); 
}

TEST(Sum_Tests, Sum_With_Different_Sizes) {
    Five five1("123");
    Five five2("2");
    Five result = five1.sum(five2);
    EXPECT_EQ(result.toStr(), "130");  
}

TEST(Sum_Tests, Sum_Result_With_Carry) {
    Five five1("444");
    Five five2("1");
    Five result = five1.sum(five2);
    EXPECT_EQ(result.toStr(), "1000"); 
}

TEST(Sum_Tests, Sum_With_Zero) {
    Five five1("123");
    Five five2("0");
    Five result = five1.sum(five2);
    EXPECT_EQ(result.toStr(), "123"); 
}

TEST(Sum_Tests, Sum_Two_Zeros) {
    Five five1("0");
    Five five2("0");
    Five result = five1.sum(five2);
    EXPECT_EQ(result.toStr(), "0");  
}

TEST(Add_Tests, Simple_Add) {
    Five five1("123");
    Five five2("432");
    five1.add(five2);
    EXPECT_EQ(five1.toStr(), "1110"); 
}

TEST(Add_Tests, Add_With_Leading_Zeros) {
    Five five1("000123");
    Five five2("000432");
    five1.add(five2);
    EXPECT_EQ(five1.toStr(), "1110");  
}

TEST(Add_Tests, Add_With_Different_Sizes) {
    Five five1("123");
    Five five2("2");
    five1.add(five2);
    EXPECT_EQ(five1.toStr(), "130");  
}

TEST(Add_Tests, Add_Result_With_Carry) {
    Five five1("444");
    Five five2("1");
    five1.add(five2);
    EXPECT_EQ(five1.toStr(), "1000");  
}

TEST(Add_Tests, Add_With_Zero) {
    Five five1("123");
    Five five2("0");
    five1.add(five2);
    EXPECT_EQ(five1.toStr(), "123");  
}

TEST(Add_Tests, Add_Two_Zeros) {
    Five five1("0");
    Five five2("0");
    five1.add(five2);
    EXPECT_EQ(five1.toStr(), "0"); 
}

TEST(Subtract_Tests, Simple_Subtract) {
    Five five1("432");
    Five five2("123");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "304");  
}

TEST(Subtract_Tests, Subtract_With_Leading_Zeros) {
    Five five1("00432");
    Five five2("00123");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "304"); 
}

TEST(Subtract_Tests, Subtract_With_Different_Sizes) {
    Five five1("123");
    Five five2("4");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "114");  
}

TEST(Subtract_Tests, Subtract_To_Zero) {
    Five five1("432");
    Five five2("432");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "0");  
}

TEST(Subtract_Tests, Subtract_Zeros) {
    Five five1("0");
    Five five2("0");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "0");  
}

TEST(Subtract_Tests, Subtract_Result_With_Leading_Zeros) {
    Five five1("100000002");
    Five five2("100000000");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "2");
}

TEST(Subtract_Tests, Subtract_Result_With_4) {
    Five five1("100000000");
    Five five2("1");
    Five result = five1.subtract(five2);
    EXPECT_EQ(result.toStr(), "44444444");
}

TEST(Remove_Tests, Simple_Remove) {
    Five five1("432");
    Five five2("123");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "304");  
}

TEST(Remove_Tests, Remove_With_Leading_Zeros) {
    Five five1("00432");
    Five five2("00123");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "304"); 
}

TEST(Remove_Tests, Remove_With_Different_Sizes) {
    Five five1("123");
    Five five2("4");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "114");  
}

TEST(Remove_Tests, Remove_To_Zero) {
    Five five1("432");
    Five five2("432");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "0");  
}

TEST(Remove_Tests, Remove_Zeros) {
    Five five1("0");
    Five five2("0");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "0");  
}

TEST(Remove_Tests, Remove_Result_With_Leading_Zeros) {
    Five five1("100000002");
    Five five2("100000000");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "2");
}

TEST(Remove_Tests, Remove_Result_With_4) {
    Five five1("100000000");
    Five five2("1");
    five1.remove(five2);
    EXPECT_EQ(five1.toStr(), "44444444");
}

TEST(Death_Tests, Invalid_Char_In_Constructor) {
    EXPECT_THROW(Five five('5'), std::invalid_argument);  
}

TEST(Death_Tests, Empty_List_In_Constructor) {
    EXPECT_THROW(Five five({}), std::invalid_argument);
}

TEST(Death_Tests, Invalid_Value_In_List_Constructor) {
    EXPECT_THROW(Five five({5}), std::invalid_argument);
    EXPECT_THROW(Five five({0, 4, 7, 2}), std::invalid_argument);
    EXPECT_THROW(Five five({1, 0, 9, 2, 4, 4}), std::invalid_argument);
    EXPECT_THROW(Five five({'6'}), std::invalid_argument);
}

TEST(Death_Tests, Invalid_String_In_Constructor) {
    EXPECT_THROW(Five five("10235"), std::invalid_argument);  
}

TEST(Death_Tests, Empty_String_In_Constructor) {
    EXPECT_THROW(Five five(""), std::invalid_argument);  
}

TEST(Death_Tests, Subtract_Negative_Result) {
    Five five1("123");
    Five five2("432");
    EXPECT_THROW(five1.subtract(five2), std::underflow_error);  
}

TEST(Death_Tests, Remove_Negative_Result) {
    Five five1("123");
    Five five2("432");
    EXPECT_THROW(five1.remove(five2), std::underflow_error);  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
