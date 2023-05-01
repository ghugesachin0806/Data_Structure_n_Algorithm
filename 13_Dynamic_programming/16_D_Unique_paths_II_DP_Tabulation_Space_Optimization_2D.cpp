// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<int> prev(col, 0);

        for (int i = 0; i < col; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            prev[i] = 1;
        }

        for (int i = 1; i < row; i++)
        {
            vector<int> curr(col, 0);
            for (int j = 0; j < col; j++)
            {
                if (obstacleGrid[i][j])
                    curr[j] = 0;
                else
                {
                    if (j > 0)
                        curr[j] = curr[j] + curr[j - 1];

                    curr[j] = curr[j] + prev[j];
                }
            }
            prev = curr;
        }

        return prev[col - 1];
    }
};