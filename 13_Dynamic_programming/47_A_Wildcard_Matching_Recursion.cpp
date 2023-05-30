// https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int sindex, int pindex, string &s, string &p)
    {
        // Base condition
        if (sindex < 0 && pindex < 0)
            return true;
        if (sindex >= 0 && pindex < 0)
            return false;

        if (sindex < 0)
        {
            while (pindex >= 0)
            {
                if (p[pindex] == '*')
                    pindex--;
                else
                    return false;
            }
            return true;
        }

        if (s[sindex] == p[pindex] || p[pindex] == '?')
            return solve(sindex - 1, pindex - 1, s, p);
        else if (p[pindex] == '*')
        {
            bool incl = solve(sindex - 1, pindex, s, p);
            bool excl = solve(sindex, pindex - 1, s, p);

            return (incl || excl);
        }
        else
            return false;
    }
    bool isMatch(string s, string p)
    {
        return solve(s.size() - 1, p.size() - 1, s, p);
    }
};