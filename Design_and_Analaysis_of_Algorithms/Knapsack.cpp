#include "Knapsack.hpp"
#include <iostream>

using std::cout;
using std::endl;

int RecursiveKnapsack(int totalWeight, const std::vector<int> &weights, const std::vector<int> &values, int n)
{
    if (n == 0 || totalWeight == 0)
    {
        return 0;
    }
    else if (weights[n - 1] > totalWeight)
    {
        return RecursiveKnapsack(totalWeight, weights, values, n - 1);
    }
    else
    {
        return std::max(
                values[n - 1] + RecursiveKnapsack(totalWeight - weights[n - 1], weights, values, n - 1),
                RecursiveKnapsack(totalWeight, weights, values, n - 1));
    }
}

int BottomUpKnapsack(int totalWeight, const std::vector<int> &weights, const std::vector<int> &values, int n)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(totalWeight + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= totalWeight; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights.at(i - 1) <= w)
            {
                dp[i][w] = std::max(
                        values[i - 1] + dp[i - 1][w - weights[i - 1]],
                        dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][totalWeight];
}
