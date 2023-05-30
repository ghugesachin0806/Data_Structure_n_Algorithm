// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &s, string &t)
    {
        if (index1 < 0 || index2 < 0)
        {
            if (index2 < 0)
                return 1;
            else
                return 0;
        }

        if (s[index1] == t[index2])
        {
            int incl = solve(index1 - 1, index2 - 1, s, t);
            int excl = solve(index1 - 1, index2, s, t);

            return incl + excl;
        }
        else
        {
            return solve(index1 - 1, index2, s, t);
        }
    }
    int numDistinct(string s, string t)
    {
        return solve(s.size() - 1, t.size() - 1, s, t);
    }
};