// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr_x, int curr_y, vector<vector<int>> &obstacleGrid, int &row, int &col)
    {
        if (curr_x == 0 && curr_y == 0 && obstacleGrid[curr_x][curr_y] == 0)
            return 1;
        if (curr_x < 0 || curr_x >= row || curr_y < 0 || curr_y >= col || obstacleGrid[curr_x][curr_y] == 1)
            return 0;

        // up call
        int up = solve(curr_x - 1, curr_y, obstacleGrid, row, col);

        // left call
        int left = solve(curr_x, curr_y - 1, obstacleGrid, row, col);

        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        return solve(row - 1, col - 1, obstacleGrid, row, col);
    }
};