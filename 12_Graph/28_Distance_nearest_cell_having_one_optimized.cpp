// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

// Here BSF will be used for step by step distance count.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int row = grid.size();
        int col = grid[0].size();

        int cnt = 1;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> ans(row, vector<int>(col, 0));

        queue<pair<int, int>> qt;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    qt.push(make_pair(i, j));
                    visited[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        qt.push(make_pair(-1, -1));

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
                    ans[curr_row][curr_col] = cnt;
                    qt.push(make_pair(curr_row, curr_col));
                }
            }
        }
        return ans;
    }
};