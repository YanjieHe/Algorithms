#include "Bitmasking.hpp"

AssignUniqueCaps::AssignUniqueCaps()
{
    for (auto &array: dp)
    {
        array.fill(-1);
    }
}

long AssignUniqueCaps::countWaysUntil(int mask, int i)
{
    const long MOD = 1000000007;
    if (mask == allMask)
    {
        return 1;
    }
    else if (i > 100)
    {
        return 0;
    }
    else if (dp[mask][i] != -1)
    {
        return dp[mask][i];
    }
    else
    {
        long ways = countWaysUntil(mask, i + 1);
        int size = capList[i].size();
        for (int j = 0; j < size; j++)
        {
            if (mask & (1 << capList[i][j]))
            {
                continue;
            }
            else
            {
                ways += countWaysUntil(mask | (1 << capList[i][j]), i + 1);
                ways = ways % MOD;
            }
        }
        dp[mask][i] = ways;
        return ways;
    }
}
