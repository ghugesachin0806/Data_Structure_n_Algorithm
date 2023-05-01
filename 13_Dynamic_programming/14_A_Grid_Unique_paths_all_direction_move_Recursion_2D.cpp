// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
// The robot can only move to top,down,left or right.
// Given the two integers m and n, return the number of possible unique paths that the robot
// can take to reach the bottom-right corner.

// Here all the 4 directions(up,down,left,right) are allowed to move

//---->  This question can't be optimized using Dynamic programming.

#include <bits/stdc++.h>
using namespace std;

int solve(int curr_x, int curr_y, vector<vector<bool>> &visited, int &row, int &col)
{
    if (curr_x == 0 && curr_y == 0)
        return 1;

    if (curr_x >= 0 && curr_x < row && curr_y >= 0 && curr_y < col && visited[curr_x][curr_y] == false)
    {
        visited[curr_x][curr_y] = true;

        int up = solve(curr_x - 1, curr_y, visited, row, col);
        int down = solve(curr_x + 1, curr_y, visited, row, col);
        int left = solve(curr_x, curr_y + 1, visited, row, col);
        int right = solve(curr_x, curr_y - 1, visited, row, col);

        visited[curr_x][curr_y] = false;

        return up + down + left + right;
    }
    else
        return 0;
}
int uniquePaths(int m, int n)
{
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int curr_x = m - 1;
    int curr_y = n - 1;

    return solve(curr_x, curr_y, visited, m, n);
}
