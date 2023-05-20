// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

#include <bits/stdc++.h>
using namespace std;

// Read the array indexing carefully in question.

int solve(int index, vector<int> &price, int length)
{
    if (index < 0)
    {
        if (length == 0)
            return 0;
        else
            return INT_MIN;
    }

    // Include call
    int incl = INT_MIN;
    if (length >= (index + 1))
        incl = solve(index, price, length - (index + 1)) + price[index];

    // Exclude call
    int excl = solve(index - 1, price, length) + 0;

    return max(incl, excl);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int curr_index = price.size() - 1;
    int length = n;

    return solve(curr_index, price, length);
}
