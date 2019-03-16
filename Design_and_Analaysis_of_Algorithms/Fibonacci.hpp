#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_FIBONACCI_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_FIBONACCI_HPP

#include <vector>

class FibonacciMemoization
{
public:
    std::vector<long> lookup;

    FibonacciMemoization(int max);

    long Compute(long n);
};

class FibonacciTabulation
{
public:
    std::vector<long> table;
    FibonacciTabulation(int max);
    long Compute(long n);
};

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_FIBONACCI_HPP
