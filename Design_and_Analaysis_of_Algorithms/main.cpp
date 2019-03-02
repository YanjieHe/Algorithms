#include <iostream>
#include "test/Test_Disjoint_Set.hpp"
#include "test/Test_Union_Find.hpp"
#include "test/Test_Kruskal_MST.hpp"
#include <cstdint>

int main()
{
    Test_Disjoint_Set::Test();
    Test_Union_Find::Test();
    Test_Kruskal_MST::Test();
    return 0;
}