// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        int maxi = INT_MIN;
        vector<vector<int>> dp(S1.size()+1, vector<int>(S2.size()+1, 0));

        for (int i = 1; i <= S1.size(); i++)
        {
            for (int j = 1; j <= S2.size(); j++)
            {
                if (S1[i - 1] == S2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi;
    }
};