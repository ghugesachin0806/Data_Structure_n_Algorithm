// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<char>> &mat, vector<vector<int>> &visited, int node_row, int node_col)
    {
        visited[node_row][node_col] = 1;
        int row = mat.size();
        int col = mat[0].size();
        int del_row[] = {0, 0, +1, -1};
        int del_col[] = {-1, +1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int temp_row = node_row + del_row[i];
            int temp_col = node_col + del_col[i];
            if (temp_row >= 0 && temp_row < row && temp_col >= 0 && temp_col < col)
            {
                if (mat[temp_row][temp_col] == 'O' && visited[temp_row][temp_col] == 0)
                {
                    DFS(mat, visited, temp_row, temp_col);
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Traverse though boundries of adj_matrix;
        for (int i = 0; i < col; i++)
        {
            if (mat[0][i] == 'O')
            {
                DFS(mat, visited, 0, i);
            }
        
            if (mat[row - 1][i] == 'O')
            {
                DFS(mat, visited, row - 1, i);
            }
        }
        for (int i = 0; i < row; i++)
        {
            if (mat[i][0] == 'O')
            {
                DFS(mat, visited, i, 0);
            }
      
            if (mat[i][col - 1] == 'O')
            {
                DFS(mat, visited, i, col - 1);
            }
        }

        // replace all the eligible 'O' with 'X'

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 'O' && visited[i][j] == 0)
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};