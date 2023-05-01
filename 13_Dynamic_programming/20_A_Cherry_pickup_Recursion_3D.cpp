// https://leetcode.com/problems/cherry-pickup-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int rob1_col, int rob2_col, int curr_row, int &row, int &col, vector<vector<int>> &grid)
    {
        if (rob1_col < 0 || rob2_col < 0 || rob1_col >= col || rob2_col >= col)
            return INT_MIN;

        if (curr_row == row - 1)
        {
            if (rob1_col == rob2_col)
                return grid[curr_row][rob1_col];
            else
                return grid[curr_row][rob1_col] + grid[curr_row][rob2_col];
        }

        int maxi = INT_MIN;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                maxi = max(maxi, solve(rob1_col + i, rob2_col + j, curr_row + 1, row, col, grid));
            }
        }

        if (rob1_col == rob2_col)
            return maxi + grid[curr_row][rob1_col];
        else
            return maxi + grid[curr_row][rob1_col] + grid[curr_row][rob2_col];
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        int rob1_col = 0;
        int rob2_col = col - 1;
        int curr_row = 0;

        return solve(rob1_col, rob2_col, curr_row, row, col, grid);
    }
};