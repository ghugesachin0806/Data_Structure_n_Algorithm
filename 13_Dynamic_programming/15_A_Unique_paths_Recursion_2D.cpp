// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr_x, int curr_y, int &row, int &col)
    {
        if (curr_x == 0 && curr_y == 0)
            return 1;

        if (curr_x < 0 || curr_x >= row || curr_y < 0 || curr_y >= col)
            return 0;

        // left call
        int left_call = solve(curr_x, curr_y - 1, row, col);

        // up call
        int right_call = solve(curr_x - 1, curr_y, row, col);

        return left_call + right_call;
    }
    int uniquePaths(int m, int n)
    {
        int curr_x = m - 1;
        int curr_y = n - 1;

        return solve(curr_x, curr_y, m, n);
    }
};