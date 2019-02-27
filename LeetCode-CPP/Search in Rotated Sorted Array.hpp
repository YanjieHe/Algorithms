#ifndef LEETCODE_CPP_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
#define LEETCODE_CPP_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP

#include "PreDefs.hpp"

class Solution {
public:
    int search(const vector<int> &nums, int target) {
        int first = 0;
        int last = nums.size();
        while (first != last) {
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[first] <= nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) {
                    last = mid;
                } else {
                    first = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[last - 1]) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
        }
        return (-1);
    }
};

void test() {
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    print("before: ");
    println(a);
    print("after: ");
    Solution solution;
    println(solution.search(a, 0));
}

#endif //LEETCODE_CPP_SEARCH_IN_ROTATED_SORTED_ARRAY_HPP
