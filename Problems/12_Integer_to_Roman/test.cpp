#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    EXPECT_EQ(Solution().intToRoman(3), "III");
}

TEST(Testing, SecondDefaultTest)
{
    EXPECT_EQ(Solution().intToRoman(58), "LVIII");
}

TEST(Testing, SpecialCaseMultipleOf5)
{
    EXPECT_EQ(Solution().intToRoman(4), "IV");
    EXPECT_EQ(Solution().intToRoman(40), "XL");
    EXPECT_EQ(Solution().intToRoman(400), "CD");
}

TEST(Testing, SpecialCaseMultipleOf10)
{
    EXPECT_EQ(Solution().intToRoman(9), "IX");
    EXPECT_EQ(Solution().intToRoman(90), "XC");
    EXPECT_EQ(Solution().intToRoman(900), "CM");
}

TEST(Testing, SpecialCase999)
{
    EXPECT_EQ(Solution().intToRoman(999), "CMXCIX");
}

TEST(Testing, MultipleOf1000)
{
    EXPECT_EQ(Solution().intToRoman(1994), "MCMXCIV");
}
