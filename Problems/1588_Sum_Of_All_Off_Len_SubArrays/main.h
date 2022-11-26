//
// 1588. Sum of All Odd Length Subarrays
//
#pragma once

#include <vector>

class Solution {
 public:
  int sumOddLengthSubarrays(std::vector<int>& arr) {
    const int arr_lenght = arr.size();
    int acc = 0;

    for (int sumLenght = 1; sumLenght <= arr_lenght; sumLenght += 2) {
      for (int i = 0; i < (arr_lenght - (sumLenght - 1)); i++) {
        for (int k = 0; k < sumLenght; k++) {
          acc += arr[k + i];
        }
      }
    }

    return acc;
  }
};