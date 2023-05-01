// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include <bits/stdc++.h>
using namespace std;

int solve(int curr_row, int curr_col, vector<vector<int>> &matrix, int &row, int &col, vector<vector<int>> &dp)
{
    if (curr_col < 0 || curr_col >= col)
        return INT_MIN;
    if (curr_row == 0)
        return matrix[curr_row][curr_col];

    if (dp[curr_row][curr_col] != -1)
        return dp[curr_row][curr_col];

    int maxi = INT_MIN;

    for (int i = -1; i < 2; i++)
    {
        maxi = max(maxi, solve(curr_row - 1, curr_col + i, matrix, row, col, dp));
    }

    dp[curr_row][curr_col] = maxi + matrix[curr_row][curr_col];

    return dp[curr_row][curr_col];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();

    // Memoization vector
    vector<vector<int>> dp(row, vector<int>(col, -1));

    int maxi = INT_MIN;

    for (int i = 0; i < col; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            maxi = max(maxi, solve(row - 1, i + j, matrix, row, col, dp));
        }
    }

    return maxi;
}
