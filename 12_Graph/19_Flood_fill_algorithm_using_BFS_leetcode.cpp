// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        vector<vector<int>> ans = image;
        int row = image.size();
        int col = image[0].size();

        int pt_val = image[sr][sc];

        queue<pair<int, int>> qt;
        qt.push(make_pair(sr, sc));
        ans[sr][sc] = color;

        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, -1, 0, +1};

        while (!qt.empty())
        {
            int curr_row = qt.front().first;
            int curr_col = qt.front().second;
            qt.pop();

            for (int i = 0; i < 4; i++)
            {
                int temp_row = curr_row + del_row[i];
                int temp_col = curr_col + del_col[i];

                if (temp_row >= 0 && temp_row < row && temp_col >= 0 && temp_col < col)
                {
                    if (image[temp_row][temp_col] == pt_val && ans[temp_row][temp_col] != color)
                    {
                        qt.push(make_pair(temp_row, temp_col));
                        ans[temp_row][temp_col] = color;
                    }
                }
            }
        }

        return ans;
    }
};