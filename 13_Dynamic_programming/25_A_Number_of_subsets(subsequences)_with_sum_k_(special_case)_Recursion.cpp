// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// Here it is also work for {0,0,0,1} and target 1

#include <bits/stdc++.h>
using namespace std;

int solve(int index, int target, vector<int> &arr)
{
    if (index < 0)
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }

    // Include call
    int incl = 0;
    if (target - arr[index] >= 0)
        incl = solve(index - 1, target - arr[index], arr);

    // Exclude call
    int excl = solve(index - 1, target, arr);

    return incl + excl;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    int curr_index = num.size() - 1;

    return solve(curr_index, tar, num);
}
