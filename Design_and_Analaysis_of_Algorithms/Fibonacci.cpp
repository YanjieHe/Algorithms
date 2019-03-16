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
        return lookup[n];
    }
    else
    {
        return lookup[n];
    }
}

FibonacciTabulation::FibonacciTabulation(int max) : table(max, -1)
{

}

long FibonacciTabulation::Compute(long n)
{
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}
