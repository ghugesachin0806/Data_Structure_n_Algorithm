// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    int curr_index = n - 1;

    // Memoization vector
    vector<int> prev(maxWeight + 1, 0);

    // Analyse the base case
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        if (weight[0] <= maxWeight)
            prev[i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(maxWeight + 1, 0);
        for (int delwt = 0; delwt <= maxWeight; delwt++)
        {
            // Exclude call
            int excl = prev[delwt];

            // Include call
            int incl = 0;
            if (delwt - weight[i] >= 0)
                incl = prev[delwt - weight[i]] + value[i];

            curr[delwt] = max(incl, excl);
        }
        prev = curr;
    }

    return prev[maxWeight];
}