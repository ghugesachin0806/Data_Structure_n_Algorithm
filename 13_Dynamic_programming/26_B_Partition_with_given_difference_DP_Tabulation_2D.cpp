// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
using namespace std;

#define Mod (int)(1e9 + 7)

class Solution
{
public:
    int findWays(vector<int> &num, int tar)
    {
        // Write your code here.
        int curr_index = num.size() - 1;

        // Memoization vector
        vector<vector<int>> dp(num.size(), vector<int>(tar + 1, 0));

        dp[0][0] = 1;

        if (num[0] <= tar)
            dp[0][num[0]] = 1;

        if (num[0] == 0)
            dp[0][num[0]] = 2;

        for (int i = 1; i < num.size(); i++)
        {
            for (int del = 0; del <= tar; del++)
            {
                // Exclude call
                int excl = dp[i - 1][del];

                // Include call
                int incl = 0;
                if (del - num[i] >= 0)
                    incl = dp[i - 1][del - num[i]];

                dp[i][del] = (incl + excl) % Mod;
            }
        }

        return dp[num.size() - 1][tar];
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