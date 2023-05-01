// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = 1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    if (i > 0)
                        dp[i][j] = dp[i][j] + dp[i - 1][j];
                    if (j > 0)
                        dp[i][j] = dp[i][j] + dp[i][j - 1];
                }
            }
        }

        return dp[row - 1][col - 1];
    }
};