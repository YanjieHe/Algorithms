#include <iostream>
#include "test/Test_Disjoint_Set.hpp"
#include "test/Test_Union_Find.hpp"
#include "test/Test_Kruskal_MST.hpp"
#include "test/Test_Prim_MST.hpp"
#include "test/Test_Dijkstra.hpp"
#include "Huffman_Coding.hpp"
#include "Fibonacci.hpp"

using std::cout;
using std::endl;

int main()
{
    Test_Disjoint_Set::Test();
    Test_Union_Find::Test();
    Test_Kruskal_MST::Test();
    Test_Prim_MST::Test();
    Test_Dijkstra::Test();
    std::string s = "abcdef";
    std::vector<int> freq = {5, 9, 12, 13, 16, 45};

    HuffmanCodes(s, freq);

    FibonacciMemoization fibonacciMemoization(100);
    cout << "fib(9) = " << fibonacciMemoization.Compute(9) << endl;
    FibonacciTabulation fibonacciTabulation(100);
    cout << "fib(9) = " << fibonacciTabulation.Compute(9) << endl;
    return 0;
}