// https://leetcode.com/problems/number-of-enclaves/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int node_row, int node_col, int row, int col, int del_row[], int del_col[])
    {
        visited[node_row][node_col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int temp_row = node_row + del_row[i];
            int temp_col = node_col + del_col[i];

            if (temp_row >= 0 && temp_row < row && temp_col < col && temp_col >= 0 && visited[temp_row][temp_col] == 0 && grid[temp_row][temp_col] == 1)
            {
                DFS(grid, visited, temp_row, temp_col, row, col, del_row, del_col);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int del_row[] = {0, 0, +1, -1};
        int del_col[] = {-1, +1, 0, 0};

        // Traverse through boundries of matrix

        for (int i = 0; i < col; i++)
        {
            if (grid[0][i] == 1)
            {
                DFS(grid, visited, 0, i, row, col, del_row, del_col);
            }

            if (grid[row - 1][i] == 1)
            {
                DFS(grid, visited, row - 1, i, row, col, del_row, del_col);
            }
        }
        for (int i = 0; i < row; i++)
        {
            if (grid[i][0] == 1)
            {
                DFS(grid, visited, i, 0, row, col, del_row, del_col);
            }
            
            if (grid[i][col - 1] == 1)
            {
                DFS(grid, visited, i, col - 1, row, col, del_row, del_col);
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