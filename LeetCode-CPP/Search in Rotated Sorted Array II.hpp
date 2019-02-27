#ifndef LEETCODE_CPP_SEARCH_IN_ROTATED_SORTED_ARRAY_II_HPP
#define LEETCODE_CPP_SEARCH_IN_ROTATED_SORTED_ARRAY_II_HPP

#include "PreDefs.hpp"

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int first = 0;
        int last = nums.size();
        while (first != last) {
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) {
                    last = mid;
                } else {
                    first = mid + 1;
                }
            } else if (nums[first] > nums[mid]) {
                if (nums[mid] < target && target <= nums[last - 1]) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            } else {
                // skip a duplicate number
                first++;
            }
        }
        return false;
    }
};

void test() {
    vector<int> a = {2, 5, 6, 0, 0, 1, 2};
    print("before: ");
    println(a);
    print("after: ");
    Solution solution;
    println(solution.search(a, 3));
}

#endif //LEETCODE_CPP_SEARCH_IN_ROTATED_SORTED_ARRAY_II_HPP
