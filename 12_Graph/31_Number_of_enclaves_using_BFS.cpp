// https://leetcode.com/problems/number-of-enclaves/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int del_row[] = {0, 0, +1, -1};
        int del_col[] = {-1, +1, 0, 0};

        queue<pair<int, int>> qt;

        // Traverse through boundries of matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // First row, first col, last row, last col
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        visited[i][j] = 1;
                        qt.push(make_pair(i, j));
                    }
                }
            }
        }
        qt.push(make_pair(-1, -1));

        while (!qt.empty())
        {
            int temp_row = qt.front().first;
            int temp_col = qt.front().second;
            qt.pop();

            if (temp_row == -1)
            {
                if (!qt.empty())
                    qt.push(make_pair(-1, -1));

                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int curr_row = temp_row + del_row[i];
                int curr_col = temp_col + del_col[i];

                if (curr_row >= 0 && curr_row < row && curr_col >= 0 && curr_col < col && visited[curr_row][curr_col] == 0 && grid[curr_row][curr_col] == 1)
                {
                    visited[curr_row][curr_col] = 1;
                    qt.push(make_pair(curr_row, curr_col));
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};