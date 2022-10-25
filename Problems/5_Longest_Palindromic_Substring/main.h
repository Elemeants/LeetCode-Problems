//
// 5. Longest Palindromic Substring
//
#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

class Solution
{
    typedef struct
    {
        size_t tail;
        size_t head;

        size_t size() const
        {
            return head - tail;
        }
    } DoubleStrPointer;

public:
    std::string longestPalindrome(std::string s)
    {
        const size_t input_size = s.size();
        DoubleStrPointer pS = {0, 0};

        for (size_t i = 0; i < input_size; i++)
        {
            if (pS.size() > (input_size - i))
            {
                break;
            }
            for (size_t j = i; j < input_size; j++)
            {
                if (isPalindrome(s.c_str(), {i, j}))
                {
                    if (pS.size() < (j - i))
                    {
                        pS.tail = i;
                        pS.head = j;
                    }
                }
            }
        }

        return s.substr(pS.tail, pS.size() + 1);
    }

    bool isPalindrome(const char *s, DoubleStrPointer pS)
    {
        if (pS.size() == 0)
        {
            return false;
        }
        else if (pS.size() == 1)
        {
            return s[pS.tail] == s[pS.head];
        }

        bool isPalindromeWord = true;
        const char *pTail = s + pS.tail;
        const char *pHead = s + pS.head;

        while (pTail < pHead)
        {
            if (*pTail != *pHead)
            {
                isPalindromeWord = false;
                break;
            }
            pTail++;
            pHead--;
        }

        return isPalindromeWord;
    }
};