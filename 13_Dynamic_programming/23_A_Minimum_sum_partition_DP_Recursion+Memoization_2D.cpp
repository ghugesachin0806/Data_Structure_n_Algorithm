
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool soln(int index, int arr[], int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;

        if (index < 0 || sum < 0)
            return false;

        if (dp[index][sum] != -1)
            return dp[index][sum];

        // incl
        bool b1 = soln(index - 1, arr, sum - arr[index], dp);
        // excl
        bool b2 = soln(index - 1, arr, sum, dp);

        return dp[index][sum] = (b1 || b2);
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(sum, -1));

        for (int i = (sum) / 2; i >= 0; i--)
        {
            if (soln(n - 1, arr, i, dp))
                return ((sum - 2 * i));
        }

        return 0;
    }
};