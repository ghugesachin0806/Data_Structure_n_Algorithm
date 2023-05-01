// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));

    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = points[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j != k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k]);
                }
            }
            dp[i][j] = dp[i][j] + points[i][j];
        }
    }

    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}