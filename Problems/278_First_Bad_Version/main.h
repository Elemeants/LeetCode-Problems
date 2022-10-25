//
// 278. First Bad Version
//
#pragma once

#include <vector>
#include <array>
#include <stdint.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;

        while (left <= right) {
            int mid = ((right - left) / 2) + left;
            if (isBadVersion (mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right + 1;
    }
};