// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));

        for (auto it : edges)
        {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            matrix[i][i] = 0;

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX)
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int temp = 0;
        int temp_cnt = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int local_cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= distanceThreshold)
                    local_cnt++;
            }
            if (local_cnt <= temp_cnt)
            {
                temp = i;
                temp_cnt = local_cnt;
            }
        }

        return temp;
    }
};