// https://leetcode.com/problems/triangle/

// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include <bits/stdc++.h>
using namespace std;

// Here we go from 1st row to last row, to avoid conditions for triangular structure

class Solution
{
public:
    int solve(int curr_row, int curr_col, int &depth, vector<vector<int>> &triangle)
    {
        if (curr_row == depth)
            return triangle[curr_row][curr_col];

        int down = solve(curr_row + 1, curr_col, depth, triangle);
        int diagonal = solve(curr_row + 1, curr_col + 1, depth, triangle);

        int curr = min(down, diagonal) + triangle[curr_row][curr_col];

        return curr;
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int curr_row = 0;
        int curr_col = 0;
        int depth = triangle.size() - 1;

        return solve(curr_row, curr_row, depth, triangle);
    }
};