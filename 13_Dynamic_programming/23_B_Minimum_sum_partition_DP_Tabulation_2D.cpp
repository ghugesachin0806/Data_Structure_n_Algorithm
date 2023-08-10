// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum = sum + arr[i];

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int del = 0; del <= sum; del++)
            {
                // Exclude call
                bool b1 = dp[i - 1][del];

                // Include call
                bool b2 = false;
                if (del - arr[i] >= 0)
                    b2 = dp[i - 1][del - arr[i]];

                dp[i][del] = (b1 || b2);
            }
        }

        // possible sum
        vector<int> ans;

        for (int i = 0; i <= sum; i++)
        {
            if (dp[n - 1][i] == true)
                ans.push_back(i);
        }

        int min_differ = INT_MAX;
        for (int i = 0; i < ans.size(); i++)
        {
            min_differ = min(min_differ, abs(ans[i] - (sum - ans[i])));
        }

        return min_differ;
    }
};