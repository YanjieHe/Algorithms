#ifndef LEETCODE_CPP_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_HPP
#define LEETCODE_CPP_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_HPP

#include "PreDefs.hpp"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) { return nums.size(); }
        else {
            int index = 2;
            for (int i = 2; i < nums.size(); i++) {
                if (nums[i] != nums[index - 2]) {
                    nums[index] = nums[i];
                    index++;
                }
            }
            return index;
        }
    }
};

void test() {
    vector<int> a = {1, 1, 1, 2, 2, 3};
    print("before: ");
    println(a);
    print("after: ");
    Solution solution;
    solution.removeDuplicates(a);
    println(a);
}

#endif //LEETCODE_CPP_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_HPP
