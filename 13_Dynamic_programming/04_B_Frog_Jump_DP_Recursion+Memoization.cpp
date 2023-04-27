// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;

int solve(int curr, vector<int> &heights, vector<int> &DP)
{
    if (curr == 0)
        return 0;

    if (DP[curr] != -1)
        return DP[curr];

    int temp1 = INT_MAX;
    int temp2 = INT_MAX;

    temp1 = solve(curr - 1, heights, DP) + abs(heights[curr] - heights[curr - 1]);

    if (curr > 1)
        temp2 = solve(curr - 2, heights, DP) + abs(heights[curr] - heights[curr - 2]);

    DP[curr] = min(temp1, temp2);

    return DP[curr];
}

int frogJump(int n, vector<int> &heights)
{
    // Memoization vector
    vector<int> DP(n + 1, -1);
    return solve(n - 1, heights, DP);
}