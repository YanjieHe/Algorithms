#ifndef LEETCODE_CPP_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
#define LEETCODE_CPP_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP

#include "PreDefs.hpp"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        } else {
            int index = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[index] != nums[i]) {
                    index++;
                    nums[index] = nums[i];
                }
            }
            return index + 1;
        }
    }
};

void test() {
    vector<int> a = {1, 1, 2};
    print("before: ");
    println(a);
    print("after: ");
    Solution solution;
    solution.removeDuplicates(a);
    println(a);
}

#endif //LEETCODE_CPP_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_HPP
