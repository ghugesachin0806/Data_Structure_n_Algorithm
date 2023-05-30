// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &s, string &t, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
        {
            if (index2 < 0)
                return 1;
            else
                return 0;
        }

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (s[index1] == t[index2])
        {
            int incl = solve(index1 - 1, index2 - 1, s, t, dp);
            int excl = solve(index1 - 1, index2, s, t, dp);

            return dp[index1][index2] = incl + excl;
        }
        else
        {
            return dp[index1][index2] = solve(index1 - 1, index2, s, t, dp);
        }
    }
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(s.size() - 1, t.size() - 1, s, t, dp);
    }
};