// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &weight, vector<int> &value, int maxWeight)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    // Exclude call
    int excl = solve(index - 1, weight, value, maxWeight);

    // Include call
    int incl = 0;
    if (maxWeight - weight[index] >= 0)
        incl = solve(index - 1, weight, value, maxWeight - weight[index]) + value[index];

    return max(incl, excl);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here

    int curr_index = n - 1;

    return solve(curr_index, weight, value, maxWeight);
}