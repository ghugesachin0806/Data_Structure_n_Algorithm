// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

#include <bits/stdc++.h>
using namespace std;

// Read the array indexing carefully in question.

int solve(int index, vector<int> &price, int length, vector<vector<int>> &dp)
{
    if (index < 0)
    {
        if (length == 0)
            return 0;
        else
            return INT_MIN;
    }

    if (dp[index][length] != -1)
        return dp[index][length];

    // Include call
    int incl = INT_MIN;
    if (length >= (index + 1))
        incl = solve(index, price, length - (index + 1), dp) + price[index];

    // Exclude call
    int excl = solve(index - 1, price, length, dp) + 0;

    dp[index][length] = max(incl, excl);

    return dp[index][length];
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int curr_index = price.size() - 1;
    int length = n;

    vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));

    return solve(curr_index, price, length, dp);
}
