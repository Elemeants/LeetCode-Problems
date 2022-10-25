//
// 8. String to Integer (atoi)
//
#pragma once

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <stdint.h>
#include <ctype.h>

typedef enum
{
    SUCCESS,
    ERROR_READING,
    OVERFLOW_DIGITS
} READ_STATE;

class Solution
{
public:
    int myAtoi(std::string s)
    {
        const int string_size = s.size();
        const char *pChar = s.c_str();
        READ_STATE state = SUCCESS;

        bool isPositive = true;
        bool signWasDetected = false;

        int parsed_value = 0;
        int digit = 0;

        // Clear Whitespaces
        while (*pChar == ' ')
        {
            pChar++;
        }

        // Sign detection
        do
        {
            if ((*pChar == '-' || *pChar == '+') && signWasDetected)
            {
                state = ERROR_READING;
            }
            else if (*pChar == '-')
            {
                pChar++;
                signWasDetected = true;
                isPositive = false;
            }
            else if (*pChar == '+')
            {
                pChar++;
                signWasDetected = true;
            }
            else
            {
                break;
            }
        } while (state == SUCCESS);

        // Digits decode...
        while (state == SUCCESS)
        {
            if (*pChar < '0' || *pChar > '9')
            {
                break;
            }

            digit = (*pChar - '0');

            if (isPositive)
            {
                if (((INT32_MAX / 10) < parsed_value))
                {
                    state = OVERFLOW_DIGITS;
                    break;
                }
                parsed_value *= 10;

                if ((INT32_MAX - parsed_value) < digit)
                {
                    state = OVERFLOW_DIGITS;
                    break;
                }
                parsed_value += digit;
            }
            else
            {
                if (((INT32_MIN / 10) > parsed_value))
                {
                    state = OVERFLOW_DIGITS;
                    break;
                }
                parsed_value *= 10;

                if ((INT32_MIN - parsed_value) > (-digit))
                {
                    state = OVERFLOW_DIGITS;
                    break;
                }
                parsed_value -= digit;
            }

            pChar++;
        }

        //
        // Check status
        //
        if (state == ERROR_READING)
        {
            return 0;
        }
        else if (state == OVERFLOW_DIGITS)
        {
            return isPositive ? INT32_MAX : INT32_MIN;
        }
        return parsed_value;
    }
};
