// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

// Here BSF will be used for step by step distance count.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    int BSF(vector<vector<int>> &grid, int node_row, int node_col)
    {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));

        if (grid[node_row][node_col] == 1)
            return 0;

        queue<pair<int, int>> qt;
        qt.push(make_pair(node_row, node_col));
        qt.push(make_pair(-1, -1));
        visited[node_row][node_col] = 1;

        int cnt = 1;
        int del_row[] = {-1, +1, 0, 0};
        int del_col[] = {0, 0, -1, +1};

        while (!qt.empty())
        {
            int temp_row = qt.front().first;
            int temp_col = qt.front().second;
            qt.pop();

            if (temp_row == -1)
            {
                cnt++;
                if (!qt.empty())
                    qt.push(make_pair(-1, -1));

                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int curr_row = temp_row + del_row[i];
                int curr_col = temp_col + del_col[i];

                if (curr_row >= 0 && curr_row < row && curr_col >= 0 && curr_col < col && visited[curr_row][curr_col] == 0)
                {
                    visited[curr_row][curr_col] = 1;
                    if (grid[curr_row][curr_col] == 1)
                        return cnt;
                    else
                        qt.push(make_pair(curr_row, curr_col));
                }
            }
        }
        return -1;
    }
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int step = BSF(grid, i, j);
                ans[i][j] = step;
            }
        }
        return ans;
    }
};