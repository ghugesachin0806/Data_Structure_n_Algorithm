// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;

int solve(int curr, vector<int> &heights)
{
    if (curr == 0)
        return 0;

    int temp1 = INT_MAX;
    int temp2 = INT_MAX;

    temp1 = solve(curr - 1, heights) + abs(heights[curr] - heights[curr - 1]);

    if (curr > 1)
        temp2 = solve(curr - 2, heights) + abs(heights[curr] - heights[curr - 2]);

    return min(temp1, temp2);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return solve(n - 1, heights);
}