#include "Divide-and-Conquer.hpp"
#include <cmath>

tuple<int, int, int> MaximumSubarray::find_max_crossing_subarray(vector<int> &A, int low, int mid, int high) {
    int left_sum = numeric_limits<int>::min();
    int sum = 0;
    int max_left;
    int max_right;
    for (int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = numeric_limits<int>::min();
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum = sum + A[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }
    return make_tuple(max_left, max_right, left_sum + right_sum);
}

tuple<int, int, int> MaximumSubarray::find_maximum_subarray(vector<int> &A, int low, int high) {
    if (high == low) {
        return make_tuple(low, high, A[low]);
    } else {
        int mid = (low + high) / 2;
        int left_low;
        int left_high;
        int left_sum;
        int right_low;
        int right_high;
        int right_sum;
        int cross_low;
        int cross_high;
        int cross_sum;
        tie(left_low, left_high, left_sum) = find_maximum_subarray(A, low, mid);
        tie(right_low, right_high, right_sum) = find_maximum_subarray(A, mid + 1, high);
        tie(cross_low, cross_high, cross_sum) = find_max_crossing_subarray(A, low, mid, high);
        if (left_sum >= right_sum && left_sum >= cross_sum) {
            return make_tuple(left_low, left_high, left_sum);
        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            return make_tuple(right_low, right_high, right_sum);
        } else {
            return make_tuple(cross_low, cross_high, cross_sum);
        }
    }
}