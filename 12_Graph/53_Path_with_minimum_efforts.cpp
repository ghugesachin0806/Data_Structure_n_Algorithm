// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        // Code here
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> max_effort(row, vector<int>(col, INT_MAX));

        queue<pair<int, int>> qt;
        qt.push(make_pair(0, 0));
        max_effort[0][0] = 0;

        int del_x[] = {0, 0, -1, +1};
        int del_y[] = {-1, +1, 0, 0};

        while (!qt.empty())
        {
            int x = qt.front().first;
            int y = qt.front().second;
            int curr_eff = max_effort[x][y];
            qt.pop();

            for (int i = 0; i < 4; i++)
            {
                int temp_x = x + del_x[i];
                int temp_y = y + del_y[i];

                if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col)
                {
                    int del = heights[x][y] - heights[temp_x][temp_y];
                    del = abs(del);
                    if (del < curr_eff)
                        del = curr_eff;

                    if (del < max_effort[temp_x][temp_y])
                    {
                        max_effort[temp_x][temp_y] = del;
                        qt.push({temp_x, temp_y});
                    }
                }
            }
        }

        return max_effort[row - 1][col - 1];
    }
};