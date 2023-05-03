// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.

    // Memoization vector
    vector<vector<bool>> dp(arr.size(), vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
            // Exclude call
            bool b1 = dp[i - 1][target];

            // Include call
            bool b2 = false;
            if (target - arr[i] >= 0)
                b2 = dp[i - 1][target - arr[i]];

            dp[i][target] = (b1 || b2);
        }
    }

    return dp[n - 1][k];
}