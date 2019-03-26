#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_DIGITDP_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_DIGITDP_HPP

#include <vector>


class DigitDP
{
public:
    std::vector<std::vector<std::vector<int>>> dp;

    static std::vector<int> GetDigits(long long x);

    long long DigitSum(int idx, int sum, int tight, const std::vector<int> &digits);

    int RangeDigitSum(int a, int b);
};

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_DIGITDP_HPP
