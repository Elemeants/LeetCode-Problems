//
// 7. Reverse Integer
//
#pragma once

#include <math.h>
#include <stdint.h>
#include <string>

class Solution {
public:
    int reverse(const int x) {
        const std::string x_str = std::to_string(x);
        const size_t no_digits = x_str.size() - (x < 0 ? 1 : 0);
        int32_t output = 0;
        bool overflow_detected = false;

        if (no_digits > 10) {
            return 0;
        }

        for (size_t digit = 0; digit < no_digits; digit++) {
            int32_t value = extractDigit(x, digit);
            if (no_digits >= 9 && digit == 0 && abs(value) > 2) {
                overflow_detected = true;
                break;
            }

            int32_t digit_to_add = (int32_t)pow(10, (no_digits - 1) - digit);
            digit_to_add *= value;

            //
            // Overflow detection
            //
            if ((INT32_MAX - abs(output)) < abs(digit_to_add)) {
                overflow_detected = true;
                break;
            }

            output += digit_to_add;
        }

        if (overflow_detected) {
            return 0;
        }

        return output;
    }

private:
    int32_t extractDigit(int x, int digit) {
        return (x / (int32_t)pow(10, digit)) % 10;
    }
};
