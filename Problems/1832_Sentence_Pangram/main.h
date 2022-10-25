//
// 1832. Check if the Sentence Is Pangram
//
#pragma once

#include <algorithm>
#include <stdint.h>

class Solution {
    const size_t NUM_OF_LETTERS_IN_ALPHABET = 26;
    const uint32_t ALPHABET_BITS_MASK = 0x3FFFFFF;
public:
    bool checkIfPangram(std::string sentence) {
        if (sentence.size () < NUM_OF_LETTERS_IN_ALPHABET) {
            return false;
        }
        
        uint32_t alphabet_mask = 0;
        
        for (auto ch : sentence) {
            if (alphabet_mask == ALPHABET_BITS_MASK) {
                break;
            }
            
            uint8_t alph_index = ch - 'a';
            uint32_t ch_mask = (1 << alph_index);
            
            if ((alphabet_mask & ch_mask) != 0) {
                continue;
            }
            
            alphabet_mask |= ch_mask;
        }
        
        return alphabet_mask == ALPHABET_BITS_MASK;
    }
};
