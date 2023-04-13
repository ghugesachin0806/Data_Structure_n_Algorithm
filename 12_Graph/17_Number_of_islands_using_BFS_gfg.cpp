// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void BFS(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> qt;
        qt.push(make_pair(row, col));
        visited[row][col] = 1;

        while (!qt.empty())
        {
            int temp_row = qt.front().first;
            int temp_col = qt.front().second;
            qt.pop();

            for (int addrow = -1; addrow <= 1; addrow++)
            {
                for (int addcol = -1; addcol <= 1; addcol++)
                {
                    int new_row = temp_row + addrow;
                    int new_col = temp_col + addcol;

                    if (new_row >= 0 && new_col >= 0 && new_row < n && new_col < m)
                    {
                        if (!visited[new_row][new_col] && grid[new_row][new_col] == '1')
                        {
                            qt.push(make_pair(new_row, new_col));
                            visited[new_row][new_col] = 1;
                        }
                    }
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0)); // vector of n*m with all elements are 0

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == '1' && !visited[row][col])
                {
                    cnt++;
                    BFS(grid, visited, row, col);
                }
            }
        }

        return cnt;
    }
};