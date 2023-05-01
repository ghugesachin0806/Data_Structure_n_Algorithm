// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr_x, int curr_y, vector<vector<int>> &obstacleGrid, int &row, int &col, vector<vector<int>> &dp)
    {
        if (curr_x == 0 && curr_y == 0 && obstacleGrid[curr_x][curr_y] == 0)
            return 1;
        if (curr_x < 0 || curr_x >= row || curr_y < 0 || curr_y >= col || obstacleGrid[curr_x][curr_y] == 1)
            return 0;

        if (dp[curr_x][curr_y] != -1)
            return dp[curr_x][curr_y];

        // up call
        int up = solve(curr_x - 1, curr_y, obstacleGrid, row, col, dp);

        // left call
        int left = solve(curr_x, curr_y - 1, obstacleGrid, row, col, dp);

        dp[curr_x][curr_y] = up + left;

        return dp[curr_x][curr_y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        return solve(row - 1, col - 1, obstacleGrid, row, col, dp);
    }
};