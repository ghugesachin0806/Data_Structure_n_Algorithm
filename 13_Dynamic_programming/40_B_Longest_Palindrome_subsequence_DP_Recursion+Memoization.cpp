// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (str1[index1] == str2[index2])
        {
            return dp[index1][index2] = 1 + solve(index1 - 1, index2 - 1, str1, str2, dp);
        }
        else
        {
            return dp[index1][index2] = max(solve(index1 - 1, index2, str1, str2, dp), solve(index1, index2 - 1, str1, str2, dp));
        }
    }

    int longestPalindromeSubseq(string s)
    {
        string straight = s;

        string reverse;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            reverse.push_back(s[i]);
        }

        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));

        return solve(s.size() - 1, s.size() - 1, straight, reverse, dp);
    }
};