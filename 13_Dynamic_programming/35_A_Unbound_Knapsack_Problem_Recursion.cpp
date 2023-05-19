// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int weight, int val[], int wt[])
    {
        if (index < 0)
            return 0;

        // Include current index
        int incl = 0;
        if (weight >= wt[index])
            incl = solve(index, weight - wt[index], val, wt) + val[index];

        // Exclude current index
        int excl = solve(index - 1, weight, val, wt) + 0;

        return max(incl, excl);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int curr_index = N - 1;

        return solve(curr_index, W, val, wt);
    }
};