// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int row, int col)
    {
        vector<int> prev(col, 1);

        for (int i = 1; i < row; i++)
        {
            vector<int> curr(col, 0);
            for (int j = 0; j < col; j++)
            {
                if (j > 0)
                    curr[j] = curr[j - 1] + prev[j];
                else
                    curr[j] = 1;
            }
            prev = curr;
        }

        return prev[col - 1];
    }

    int uniquePaths(int m, int n)
    {
        // code here
        return solve(m, n);
    }
};