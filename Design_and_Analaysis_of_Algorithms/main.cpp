#include <iostream>
#include "test/Test_Disjoint_Set.hpp"
#include "test/Test_Union_Find.hpp"
#include "test/Test_Kruskal_MST.hpp"
#include "test/Test_Prim_MST.hpp"
#include "test/Test_Dijkstra.hpp"
#include "Huffman_Coding.hpp"
#include "Fibonacci.hpp"
#include "Bitmasking.hpp"
#include "Wildcard Pattern Matching.hpp"
#include "Knapsack.hpp"
#include "DigitDP.hpp"

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
    AssignUniqueCaps assignUniqueCaps;

    std::vector<std::vector<int>> input = {
            {5, 100, 1},
            {2},
            {5, 100}
    };
    for (int i = 0; i < input.size(); i++)
    {
        for (int item: input.at(i))
        {
            assignUniqueCaps.capList[item].push_back(i);
        }
    }
    assignUniqueCaps.allMask = (1 << static_cast<int>(input.size())) - 1;
    cout << assignUniqueCaps.countWaysUntil(0, 1) << endl;

    cout << std::boolalpha << WildcardPatternMatching("xyxzzxy", "x***x?") << endl;

    cout << RecursiveKnapsack(50, {10, 20, 30}, {60, 100, 120}, 3) << endl;
    cout << BottomUpKnapsack(50, {10, 20, 30}, {60, 100, 120}, 3) << endl;

    DigitDP digitDP;
    cout << digitDP.RangeDigitSum(123, 1024) << endl;
    return 0;
}