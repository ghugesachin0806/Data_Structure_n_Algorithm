// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // code here
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> qt;
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        int del_x[] = {0, 0, -1, +1};
        int del_y[] = {-1, +1, 0, 0};

        qt.push({source.first, source.second});
        dist[source.first][source.second] = 0;

        while (!qt.empty())
        {
            int x = qt.front().first;
            int y = qt.front().second;
            int node_dist = dist[x][y];
            qt.pop();

            for (int i = 0; i < 4; i++)
            {
                int temp_x = x + del_x[i];
                int temp_y = y + del_y[i];

                if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col && grid[temp_x][temp_y] == 1)
                {
                    if (dist[temp_x][temp_y] > node_dist + 1)
                    {
                        dist[temp_x][temp_y] = node_dist + 1;
                        qt.push({temp_x, temp_y});
                    }
                }
            }
        }

        if (dist[destination.first][destination.second] == INT_MAX)
            return -1;
        else
            return dist[destination.first][destination.second];
    }
};