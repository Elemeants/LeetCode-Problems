//
// 692. Top K Frequent Words
//
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <iterator>

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::vector<std::string> output;
        std::vector<std::pair<std::string, int>> wordCount;

        output.reserve(k);

        for (const std::string& str : words) {
            auto e = std::find_if(wordCount.begin(), wordCount.end(),
                [str](const std::pair<std::string, int>& p) -> bool { return p.first == str; }
            );
            if (e == wordCount.end()) {
                wordCount.push_back(std::make_pair(str, 1));
            }
            else {
                e->second++;
            }
        }

        std::sort(wordCount.begin(), wordCount.end(),
            [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) -> bool {
                if (a.second < b.second) { return false; }
                if (a.second > b.second) { return true; }
                
                return lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end());
            });

        auto itEnd = wordCount.begin();
        std::advance(itEnd, k);
        std::transform(wordCount.begin(), itEnd, std::back_inserter(output),
            [](const std::pair<std::string, int>& in) -> std::string {
                return in.first;
            });

        return output;
    }
};
