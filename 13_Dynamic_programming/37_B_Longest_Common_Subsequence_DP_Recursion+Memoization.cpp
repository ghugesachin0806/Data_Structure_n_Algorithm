// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2])
        {
            dp[index1][index2] = 1 + solve(index1 - 1, index2 - 1, text1, text2, dp);
            return dp[index1][index2];
        }

        dp[index1][index2] = max(solve(index1 - 1, index2, text1, text2, dp), solve(index1, index2 - 1, text1, text2, dp));
        return dp[index1][index2];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int index1 = text1.size() - 1;
        int index2 = text2.size() - 1;

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return solve(index1, index2, text1, text2, dp);
    }
};