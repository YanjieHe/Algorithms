#ifndef LEETCODE_CPP_4SUM_HPP
#define LEETCODE_CPP_4SUM_HPP

#include "PreDefs.hpp"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) { return result; }
        else {
            sort(nums.begin(), nums.end());

            unordered_map<int, vector<tuple<int, int>>> cache;

            for (int a = 0; a < nums.size(); a++) {
                for (int b = a + 1; b < nums.size(); b++) {
                    cache[nums[a] + nums[b]].push_back(std::make_tuple(a, b));
                }
            }
            for (int c = 0; c < nums.size(); c++) {
                for (int d = c + 1; d < nums.size(); d++) {
                    const int key = target - nums[c] - nums[d];
                    if (cache.find(key) == cache.end()) {
                        // pass
                    } else {
                        const auto &vec = cache[key];
                        for (int k = 0; k < vec.size(); k++) {
                            if (c <= std::get<1>(vec[k])) {
                                // pass
                            } else {
                                result.push_back({
                                                         nums[std::get<0>(vec[k])],
                                                         nums[std::get<1>(vec[k])],
                                                         nums[c],
                                                         nums[d]
                                                 });
                            }
                        }
                    }
                }
            }
            sort(result.begin(), result.end());
            result.erase(unique(result.begin(), result.end()), result.end());
            return result;
        }
    }
};

#endif //LEETCODE_CPP_4SUM_HPP
