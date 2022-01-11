#include <string>

#include <gtest/gtest.h>

#include "StringLineProvider.hpp"
#include "Regex.h"

struct RegexFixture : public testing::Test
{
    std::stringstream oss;
    std::vector<std::string> stringsToBeFound, rejectedStrings;
    void CheckAllStringsFound(const char* mask)
    {
        auto v = stringsToBeFound;
        v.insert(v.end(), rejectedStrings.begin(), rejectedStrings.end());
        regex::Match(std::make_shared<::StringLineProvider>(v), mask, oss);
        std::size_t count = 0, lineNumber = 0;
        std::string s;
        while (std::getline(oss, s, '\n'))
        {
            if (count == stringsToBeFound.size())
            {
                FAIL() << "output stream contains too much strings, latest " << s;
            }
            ASSERT_EQ(s, std::to_string(++lineNumber) + ":" + stringsToBeFound[count++]);
        }
        ASSERT_EQ(count, stringsToBeFound.size());
    }
};

TEST_F (RegexFixture, BeginEndRandomVariableLength)
{
    stringsToBeFound = 
    {
        "abc",
        "abcd",
        "dabc",
        "dabcd",
        "edabc",
        "dabcde",
        "acbabcbac"
    };
    CheckAllStringsFound("*abc*");
}

TEST_F (RegexFixture, BeginRandomVariableLength)
{
    stringsToBeFound = 
    {
        "abc",
        "dabc",
        "edabc",
        "abcd abc"
    };
    rejectedStrings = 
    {
        "abcd"
    };
    CheckAllStringsFound("*abc");
}

TEST_F (RegexFixture, EndRandomVariableLength)
{
    stringsToBeFound = 
    {
        "abc",
        "abcd",
        "abcde",
        "dabc abc"
    };
    rejectedStrings =
    {
        "dabc"
    };
    CheckAllStringsFound("abc*");
}

TEST_F (RegexFixture, StrictSearch)
{
    stringsToBeFound = 
    {
        "abc",
    };
    rejectedStrings =
    {
        "dabc",
        "abcd",
        "dabcd"
    };
    CheckAllStringsFound("abc");
}

TEST_F (RegexFixture, EndOneLength)
{
    stringsToBeFound = 
    {
        "abcd"
    };
    rejectedStrings = 
    {
        "abcde"
    };
    CheckAllStringsFound("abc?");
}

TEST_F (RegexFixture, BeginOneLength)
{
    stringsToBeFound = 
    {
        "dabc"
    };
    rejectedStrings = 
    {
        "edabc"
    };
    CheckAllStringsFound("?abc");
}

TEST_F (RegexFixture, BeginEndOneLength)
{
    stringsToBeFound = 
    {
        "dabcd"
    };
    rejectedStrings = 
    {
        "edabcde"
    };
    CheckAllStringsFound("?abc?");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
