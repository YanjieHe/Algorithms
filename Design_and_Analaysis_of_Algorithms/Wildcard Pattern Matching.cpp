#include "Wildcard Pattern Matching.hpp"

bool WildcardPatternMatching(std::string text, std::string pattern)
{
    if (pattern.size() == 0)
    {
        return text.size() == 0;
    }
    else
    {
        std::vector<std::vector<bool>> lookup(
                text.size() + 1,
                std::vector<bool>(pattern.size() + 1, false));
        lookup[0][0] = true;
        for (int j = 1; j <= pattern.size(); j++)
        {
            if (pattern[j - 1] == '*')
            {
                lookup[0][j] = lookup[0][j - 1];
            }
        }
        for (int i = 1; i <= text.size(); i++)
        {
            for (int j = 1; j <= pattern.size(); j++)
            {
                if (pattern[j - 1] == '*')
                {
                    lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
                }
                else if (pattern[j - 1] == '?' || text[i - 1] == pattern[j - 1])
                {
                    lookup[i][j] = lookup[i - 1][j - 1];
                }
                else
                {
                    lookup[i][j] = false;
                }
            }
        }
        return lookup[text.size()][pattern.size()];
    }
}
