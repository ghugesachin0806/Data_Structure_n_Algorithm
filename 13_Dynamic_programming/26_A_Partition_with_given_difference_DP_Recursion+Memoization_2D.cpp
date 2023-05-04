// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
using namespace std;

#define Mod (int)(1e9 + 7)

class Solution
{
public:
    int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (index < 0)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        // Include call
        int incl = 0;
        if (target - arr[index] >= 0)
            incl = solve(index - 1, target - arr[index], arr, dp);

        // Exclude call
        int excl = solve(index - 1, target, arr, dp);

        dp[index][target] = (incl + excl) % Mod;

        return dp[index][target];
    }

    int findWays(vector<int> &num, int tar)
    {
        int curr_index = num.size() - 1;

        // Memoization vector
        vector<vector<int>> dp(num.size(), vector<int>(tar + 1, -1));

        return solve(curr_index, tar, num, dp);
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum = sum + arr[i];
        }

        if ((sum - d) < 0 || (sum - d) % 2 == 1)
            return 0;

        return findWays(arr, (sum - d) / 2);
    }
};