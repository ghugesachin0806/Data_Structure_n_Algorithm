// https://leetcode.com/problems/perfect-squares/

// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int target, vector<int> &dp)
    {
        if (target == 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        int temp_ans = target;
        for (int i = 1; i * i <= target; i++)
        {
            temp_ans = min(temp_ans, solve(target - i * i, dp) + 1);
        }

        dp[target] = temp_ans;

        return dp[target];
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};