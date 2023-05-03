// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

bool solve(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (sum < 0)
        return false;
    if (index == 0)
    {
        // return (arr[index]==sum);
        if (arr[index] == sum)
            return true;
        else
            return false;
    }

    if (dp[index][sum] != -1)
        return dp[index][sum];

    // Include call
    bool b1 = solve(index - 1, sum - arr[index], arr, dp);

    // Exclude call
    bool b2 = solve(index - 1, sum, arr, dp);

    dp[index][sum] = (b1 || b2);

    return dp[index][sum];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    int curr_index = arr.size() - 1;
    int sum = k;

    // Memoization vector
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));

    return solve(curr_index, sum, arr, dp);
}