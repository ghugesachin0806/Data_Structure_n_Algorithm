// https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr_x, int curr_y, int &row, int &col, vector<vector<int>> &grid)
    {
        if (curr_x == 0 && curr_y == 0)
            return grid[0][0];

        if (curr_x < 0 || curr_x >= row || curr_y < 0 || curr_y >= col)
            return INT_MAX;

        // up call
        int up = solve(curr_x - 1, curr_y, row, col, grid);

        // left call
        int left = solve(curr_x, curr_y - 1, row, col, grid);

        if (up != INT_MAX)
            up = up + grid[curr_x][curr_y];

        if (left != INT_MAX)
            left = left + grid[curr_x][curr_y];

        return min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        int curr_x = row - 1;
        int curr_y = col - 1;

        return solve(curr_x, curr_y, row, col, grid);
    }
};