// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int weight, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (index < 0)
            return 0;

        if (dp[index][weight] != -1)
            return dp[index][weight];

        // Include current index
        int incl = 0;
        if (weight >= wt[index])
            incl = solve(index, weight - wt[index], val, wt, dp) + val[index];

        // Exclude current index
        int excl = solve(index - 1, weight, val, wt, dp) + 0;

        dp[index][weight] = max(incl, excl);

        return dp[index][weight];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int curr_index = N - 1;

        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        return solve(curr_index, W, val, wt, dp);
    }
};