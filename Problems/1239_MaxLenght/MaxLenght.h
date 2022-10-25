#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int maxLength(const std::vector<std::string>& arr) {
        std::vector<std::set<char>> arrStrSets = convertVectorOfStringsToVectorOfSets(arr);
        return calculateLargestSubsequence (arrStrSets);
    }
private:
    std::vector<std::set<char>> convertVectorOfStringsToVectorOfSets(const std::vector<std::string>& arr) {
        std::vector<std::set<char>> arrStrSets;

        for (const std::string str : arr) {
            std::set<char> uniqueChars(str.begin(), str.end());
            if (uniqueChars.size() != str.size()) {
                continue;
            }
            arrStrSets.push_back(uniqueChars);
        }

        return arrStrSets;
    }

    int calculateLargestSubsequence(const std::vector<std::set<char>>& arr) {
        size_t       maxLenght = 0;
        const size_t arr_size = arr.size();

        if (arr_size == 0) {
            return 0;
        }
        else if (arr_size == 1) {
            return arr[0].size();
        }

        for (size_t x = 0; x < arr_size; x++) {
            std::vector<std::pair<size_t, std::set<char>>> accepted;
            accepted.push_back(std::make_pair(x, arr[x]));

            for (size_t y = x + 1; y < arr_size; y++) {
                auto it = std::find_if(accepted.begin(), accepted.end(),
                    [&](const std::pair<size_t, std::set<char>> pair) -> bool {
                        return !canJoin(pair.second.begin(), pair.second.end(), arr[y].begin(), arr[y].end());
                    });
                if (it == accepted.end()) {
                    accepted.push_back(std::make_pair(y, arr[y]));
                } else if (it->first > x) {
                    accepted.erase(it, accepted.end());
                    accepted.push_back(std::make_pair(y, arr[y]));
                }

                saveCurrentSubsequenceLenght(maxLenght, accepted);
            }

            saveCurrentSubsequenceLenght(maxLenght, accepted);
        }

        return maxLenght;
    }

    void saveCurrentSubsequenceLenght(size_t& maxLenght, const std::vector<std::pair<size_t, std::set<char>>>& arr) {
        size_t size = 0;
        for (std::pair<size_t, std::set<char>> pair : arr) {
            size += pair.second.size();
        }

        if (maxLenght < size) {
            maxLenght = size;
        }
    }

    template<class InputIt1, class InputIt2>
    bool canJoin(InputIt1 first1, InputIt1 last1,
        InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1 && first2 != last2) {
            if (*first1 < *first2) {
                ++first1;
            }
            else {
                if (!(*first2 < *first1)) {
                    return false;
                }
                ++first2;
            }
        }
        return true;
    }
};
