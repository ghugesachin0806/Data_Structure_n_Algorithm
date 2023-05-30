// https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int sindex, int pindex, string &s, string &p, vector<vector<int>> &dp)
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

        if (dp[sindex][pindex] != -1)
            return dp[sindex][pindex];

        if (s[sindex] == p[pindex] || p[pindex] == '?')
            return dp[sindex][pindex] = solve(sindex - 1, pindex - 1, s, p, dp);
        else if (p[pindex] == '*')
        {
            bool incl = solve(sindex - 1, pindex, s, p, dp);
            bool excl = solve(sindex, pindex - 1, s, p, dp);

            return dp[sindex][pindex] = (incl || excl);
        }
        else
            return dp[sindex][pindex] = false;
    }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));

        return solve(s.size() - 1, p.size() - 1, s, p, dp);
    }
};