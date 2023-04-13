// https://leetcode.com/problems/rotting-oranges/

// Here simultaneous levelbased operation is required , so BFS algorithm will be used

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> qt;

        int cnt = 0;

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> temp_grid = grid;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    qt.push(make_pair(i, j));
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
                int n_row = temp_row + del_row[i];
                int n_col = temp_col + del_col[i];

                if (n_row < row && n_row >= 0 && n_col < col && n_col >= 0)
                {
                    if (temp_grid[n_row][n_col] == 1)
                    {
                        qt.push(make_pair(n_row, n_col));
                        temp_grid[n_row][n_col] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (temp_grid[i][j] == 1)
                    cnt = 0;
            }
        }
        return cnt - 1;
    }
};