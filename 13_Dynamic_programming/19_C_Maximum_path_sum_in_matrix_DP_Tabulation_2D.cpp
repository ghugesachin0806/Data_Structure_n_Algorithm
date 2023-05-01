// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();

    // Memoization vector
    vector<vector<int>> dp(row, vector<int>(col, INT_MIN));

    for (int i = 0; i < col; i++)
        dp[0][i] = matrix[0][i];

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int maxi = INT_MIN;
            for (int del = -1; del < 2; del++)
            {
                if (j + del >= 0 && j + del < col)
                    maxi = max(maxi, dp[i - 1][j + del]);
            }
            dp[i][j] = maxi + matrix[i][j];
        }
    }

    int maxim = INT_MIN;

    for (int i = 0; i < col; i++)
        maxim = max(maxim, dp[row - 1][i]);

    return maxim;
}