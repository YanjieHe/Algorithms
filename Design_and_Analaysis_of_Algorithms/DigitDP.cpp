#include "DigitDP.hpp"

std::vector<int> DigitDP::GetDigits(long long x)
{
    std::vector<int> digits;
    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    return digits;
}

long long DigitDP::DigitSum(int idx, int sum, int tight, const std::vector<int> &digits)
{
    if (idx == -1)
    {
        return sum;
    }
    else if (dp[idx][sum][tight] != -1 && tight != -1)
    {
        return dp[idx][sum][tight];
    }
    else
    {
        long long result = 0;
        int k = (tight) ? digits[idx] : 9;
        for (int i = 0; i <= k; i++)
        {
            int newTight = (digits[idx] == i) ? tight : 0;
            result += DigitSum(idx - 1, sum + i, newTight, digits);
        }
        if (!tight)
        {
            dp[idx][sum][tight] = result;
        }
        return result;
    }
}

int DigitDP::RangeDigitSum(int a, int b)
{
    dp = std::vector<
            std::vector<
                    std::vector<int>>>(20,
                                       std::vector<std::vector<int>>(
                                               180, std::vector<int>(2, -1)));
    std::vector<int> digitA = GetDigits(a - 1);
    long long ans1 = DigitSum(digitA.size() - 1, 0, 1, digitA);

    std::vector<int> digitB = GetDigits(b);
    long long ans2 = DigitSum(digitB.size() - 1, 0, 1, digitB);
    return static_cast<int>(ans2 - ans1);
}
