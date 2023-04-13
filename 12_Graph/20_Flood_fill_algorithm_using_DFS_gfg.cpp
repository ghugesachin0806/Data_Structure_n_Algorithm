// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<int>> &image, vector<vector<int>> &ans, int sr, int sc, int newColor, int pt_val)
    {
        ans[sr][sc] = newColor;

        int row = image.size();
        int col = image[0].size();
        int del_row[] = {-1, +1, 0, 0};
        int del_col[] = {0, 0, -1, +1};

        for (int i = 0; i < 4; i++)
        {
            int temp_row = sr + del_row[i];
            int temp_col = sc + del_col[i];

            if (temp_row < row && temp_row >= 0 && temp_col < col && temp_col >= 0)
            {
                if (image[temp_row][temp_col] == pt_val && ans[temp_row][temp_col] != newColor)
                {
                    DFS(image, ans, temp_row, temp_col, newColor, pt_val);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        int row = image.size();
        int col = image[0].size();

        int pt_val = image[sr][sc];
        vector<vector<int>> ans = image;

        DFS(image, ans, sr, sc, newColor, pt_val);

        return ans;
    }
};