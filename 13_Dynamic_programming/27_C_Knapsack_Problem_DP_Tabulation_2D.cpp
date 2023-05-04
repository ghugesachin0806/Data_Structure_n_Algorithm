// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    int curr_index = n - 1;

    // Memoization vector
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // Analyse the base case
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        if (weight[0] <= maxWeight)
            dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int delwt = 0; delwt <= maxWeight; delwt++)
        {
            // Exclude call
            int excl = dp[i - 1][delwt];

            // Include call
            int incl = 0;
            if (delwt - weight[i] >= 0)
                incl = dp[i - 1][delwt - weight[i]] + value[i];

            dp[i][delwt] = max(incl, excl);
        }
    }

    return dp[n - 1][maxWeight];
}