// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
using namespace std;

// below can be solved using DFS or BFS as well

class Solution
{
public:
    void DFS(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &vect, int node_row, int node_col, int base_row, int base_col)
    {
        int row = grid.size();
        int col = grid[0].size();
        visited[node_row][node_col] = 1;
        vect.push_back(make_pair(node_row - base_row, node_col - base_col));

        int del_row[] = {0, 0, +1, -1};
        int del_col[] = {-1, +1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int temp_row = node_row + del_row[i];
            int temp_col = node_col + del_col[i];

            if (temp_row < row && temp_col < col && temp_row >= 0 && temp_col >= 0 && grid[temp_row][temp_col] == 1 && visited[temp_row][temp_col] == 0)
            {
                DFS(grid, visited, vect, temp_row, temp_col, base_row, base_col);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int row = grid.size();
        int col = grid[0].size();

        set<vector<pair<int, int>>> st;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    vector<pair<int, int>> vect;
                    DFS(grid, visited, vect, i, j, i, j);
                    st.insert(vect);
                }
            }
        }

        return st.size();
    }
};