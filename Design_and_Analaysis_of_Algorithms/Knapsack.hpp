#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_KNAPSACK_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_KNAPSACK_HPP

#include <vector>
#include <algorithm>

int RecursiveKnapsack(int totalWeight, const std::vector<int> &weights,
                      const std::vector<int> &values, int n);

int BottomUpKnapsack(int totalWeight, const std::vector<int> &weights,
                     const std::vector<int> &values, int n);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_KNAPSACK_HPP
