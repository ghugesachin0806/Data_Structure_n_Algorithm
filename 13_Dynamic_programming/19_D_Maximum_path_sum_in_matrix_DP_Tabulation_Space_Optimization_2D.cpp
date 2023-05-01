// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();

    // Memoization vector
    vector<int> prev(col, INT_MIN);

    for (int i = 0; i < col; i++)
        prev[i] = matrix[0][i];

    for (int i = 1; i < row; i++)
    {
        vector<int> curr(col, INT_MIN);
        for (int j = 0; j < col; j++)
        {
            for (int del = -1; del < 2; del++)
            {
                if (j + del >= 0 && j + del < col)
                    curr[j] = max(curr[j], prev[j + del]);
            }
            curr[j] = curr[j] + matrix[i][j];
        }
        prev = curr;
    }

    int maxim = INT_MIN;

    for (int i = 0; i < col; i++)
        maxim = max(maxim, prev[i]);

    return maxim;
}