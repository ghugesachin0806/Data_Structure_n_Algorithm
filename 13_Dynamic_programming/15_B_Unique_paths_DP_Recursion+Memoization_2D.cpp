// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &dp, int curr_x, int curr_y, int &row, int &col)
    {
        if (curr_x == 0 && curr_y == 0)
            return 1;

        if (curr_x < 0 || curr_x >= row || curr_y < 0 || curr_y >= col)
            return 0;

        if (dp[curr_x][curr_y] != -1)
            return dp[curr_x][curr_y];

        // left call
        int left_call = solve(dp, curr_x, curr_y - 1, row, col);

        // up call
        int right_call = solve(dp, curr_x - 1, curr_y, row, col);

        dp[curr_x][curr_y] = left_call + right_call;

        return dp[curr_x][curr_y];
    }
    int uniquePaths(int m, int n)
    {
        int curr_x = m - 1;
        int curr_y = n - 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dp, curr_x, curr_y, m, n);
    }
};