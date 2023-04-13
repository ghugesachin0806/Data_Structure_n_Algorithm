// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void DFS(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col)
    {
        int t_row = grid.size();
        int t_col = grid[0].size();

        visited[row][col] = 1;

        if (col + 1 < t_col && !visited[row][col + 1] && grid[row][col + 1] == '1')
            DFS(grid, visited, row, col + 1);
        if (col - 1 >= 0 && !visited[row][col - 1] && grid[row][col - 1] == '1')
            DFS(grid, visited, row, col - 1);
        if (row + 1 < t_row && !visited[row + 1][col] && grid[row + 1][col] == '1')
            DFS(grid, visited, row + 1, col);
        if (row - 1 >= 0 && !visited[row - 1][col] && grid[row - 1][col] == '1')
            DFS(grid, visited, row - 1, col);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n_row = grid.size();
        int n_col = grid[0].size();

        // vector with n*m grid and all elements are zero
        vector<vector<int>> visited(n_row, vector<int>(n_col, 0));
        int cnt = 0;

        for (int row = 0; row < n_row; row++)
        {
            for (int col = 0; col < n_col; col++)
            {
                if (grid[row][col] == '1' && !visited[row][col])
                {
                    DFS(grid, visited, row, col);
                    cnt++;
                }
            }
        }
        return cnt++;
    }
};