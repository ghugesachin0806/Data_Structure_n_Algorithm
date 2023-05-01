// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &points, int last_task)
{
    if (n < 0)
        return 0;

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last_task)
            maxi = max(maxi, points[n][i] + solve(n - 1, points, i));
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    
    int curr_day = n - 1; // due to 0th based indexing
    int last_task = 3;    // out of given task

    return solve(curr_day, points, last_task);
}