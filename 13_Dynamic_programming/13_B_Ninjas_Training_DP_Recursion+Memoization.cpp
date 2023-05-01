// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &points, int last_task, vector<vector<int>> &DP)
{
    if (n < 0)
        return 0;

    if (DP[n][last_task] != -1)
        return DP[n][last_task];

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last_task)
            maxi = max(maxi, points[n][i] + solve(n - 1, points, i, DP));
    }

    DP[n][last_task] = maxi;
    return DP[n][last_task];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    // here matrix is n*4 because , we are sending one 3rd invalid task at start.
    vector<vector<int>> DP(n + 1, vector<int>(4, -1));
    int curr_day = n - 1; // due to 0th based indexing
    int last_task = 3;    // out of given task

    return solve(curr_day, points, last_task, DP);
}