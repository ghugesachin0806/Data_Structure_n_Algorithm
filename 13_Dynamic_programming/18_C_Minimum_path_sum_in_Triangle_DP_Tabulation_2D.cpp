// https://leetcode.com/problems/triangle/

// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        int col = triangle[row - 1].size();

        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j > 0)
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                else
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
        }

        int mini = INT_MAX;

        for (int i = 0; i < col; i++)
        {
            mini = min(mini, dp[row - 1][i]);
        }

        return mini;
    }
};