// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int row, int col)
    {
        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = 1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // Adding up and left grid ways
                if (i > 0)
                    dp[i][j] = dp[i][j] + dp[i - 1][j];
                if (j > 0)
                    dp[i][j] = dp[i][j] + dp[i][j - 1];
            }
        }

        return dp[row - 1][col - 1];
    }

    int uniquePaths(int m, int n)
    {
        // code here
        return solve(m, n);
    }
};