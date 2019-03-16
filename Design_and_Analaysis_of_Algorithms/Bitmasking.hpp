#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_BITMASKING_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_BITMASKING_HPP

#include <vector>
#include <array>

class AssignUniqueCaps
{
public:
    std::array<std::vector<int>, 101> capList;
    std::array<std::array<int, 101>, 1025> dp;
    int allMask;

    AssignUniqueCaps();

    long countWaysUntil(int mask, int i);
};

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_BITMASKING_HPP
