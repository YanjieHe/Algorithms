#ifndef INTRODUCTION_TO_ALGORITHMS_DIVIDE_AND_CONQUER_HPP
#define INTRODUCTION_TO_ALGORITHMS_DIVIDE_AND_CONQUER_HPP

#include <vector>
#include <numeric>
#include <tuple>
#include <iostream>

using std::vector;
using std::numeric_limits;
using std::tie;
using std::make_tuple;
using std::tuple;
using std::cout;
using std::endl;

class MaximumSubarray {
public:
    static tuple<int, int, int> find_max_crossing_subarray(vector<int> &A, int low, int mid, int high);

    static tuple<int, int, int> find_maximum_subarray(vector<int> &A, int low, int high);

    static void test() {
        vector<int> A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
        int low, high, sum;
        tie(low, high, sum) = find_maximum_subarray(A, 0, A.size() - 1);
        cout << low << " " << high << " " << sum << endl;
    }
};

#endif //INTRODUCTION_TO_ALGORITHMS_DIVIDE_AND_CONQUER_HPP
