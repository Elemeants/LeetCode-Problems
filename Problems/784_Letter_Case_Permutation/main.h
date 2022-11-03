//
// 784. Letter Case Permutation
//
#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <ctype.h>
#include <stdint.h>

class Solution {
public:
    std::vector<std::string> letterCasePermutation(const std::string& s) {
        std::string local = s;
        std::vector<std::pair<int, char>> lettersToPermute;
        // Get indexes of letters
        for (size_t i = 0; i < local.length(); i++) {
          if (isalpha(local[i])) {
            lettersToPermute.push_back(std::make_pair(i, tolower(local[i])));
          }
        }

        // Since we permute over lower and upper it is like a binary index
        const size_t no_of_permutations = 1 << lettersToPermute.size();
        std::vector<std::string> permutations(no_of_permutations);

        // Generate a binary mask that represents 0s as lower and 1s as upper
        for (uint32_t mask = 0; mask < no_of_permutations; mask++) {
          // Update the string to upper if there is a 1 on the mask for that letter
          for (uint8_t letter = 0; letter < lettersToPermute.size(); letter++) {
            bool mayus = ((mask & (1 << letter)) != 0);
            local[lettersToPermute[letter].first] = lettersToPermute[letter].second;
            if (mayus) {
              local[lettersToPermute[letter].first] = toupper(lettersToPermute[letter].second);
            }
          }
          // Set this combination to the output vector
          permutations[mask] = (local);
        }

        return permutations;
    }
};