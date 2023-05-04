// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &weight, vector<int> &value, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];

    // Exclude call
    int excl = solve(index - 1, weight, value, maxWeight, dp);

    // Include call
    int incl = 0;
    if (maxWeight - weight[index] >= 0)
        incl = solve(index - 1, weight, value, maxWeight - weight[index], dp) + value[index];

    dp[index][maxWeight] = max(incl, excl);

    return dp[index][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here

    int curr_index = n - 1;

    // Memoization vector
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    return solve(curr_index, weight, value, maxWeight, dp);
}