// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// Here it is also work for {0,0,0,1} and target 1

#include <bits/stdc++.h>
using namespace std;

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

            dp[i][del] = incl + excl;
        }
    }

    return dp[num.size() - 1][tar];
}