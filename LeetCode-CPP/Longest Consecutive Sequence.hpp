#ifndef LEETCODE_CPP_LONGEST_CONSECUTIVE_SEQUENCE_HPP
#define LEETCODE_CPP_LONGEST_CONSECUTIVE_SEQUENCE_HPP

#include "PreDefs.hpp"

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, bool> used;
        for (auto i: nums) {
            used[i] = false;
        }
        int longest = 0;
        for (auto i: nums) {
            if (used[i]) {
                // pass
            } else {
                int length = 1;
                used[i] = true;
                // forward
                for (int j = i + 1; used.find(j) != used.end(); j++) {
                    used[j] = true;
                    length++;
                }
                // backward
                for (int j = i - 1; used.find(j) != used.end(); j--) {
                    used[j] = true;
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};

#endif //LEETCODE_CPP_LONGEST_CONSECUTIVE_SEQUENCE_HPP
