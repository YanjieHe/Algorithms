#include "Fibonacci.hpp"

FibonacciMemoization::FibonacciMemoization(int max) : lookup(max, -1)
{

}

long FibonacciMemoization::Compute(long n)
{
    if (lookup[n] == -1)
    {
        if (n <= 1)
        {
            lookup[n] = n;
        }
        else
        {
            lookup[n] = Compute(n - 1) + Compute(n - 2);
        }
    }
    else
    {
        return lookup[n];
    }
}
