#include <iostream>
#include "test/Test_Disjoint_Set.hpp"
#include "test/Test_Union_Find.hpp"
#include "test/Test_Kruskal_MST.hpp"
#include "test/Test_Prim_MST.hpp"
#include "test/Test_Dijkstra.hpp"
#include "Huffman_Coding.hpp"

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
    return 0;
}