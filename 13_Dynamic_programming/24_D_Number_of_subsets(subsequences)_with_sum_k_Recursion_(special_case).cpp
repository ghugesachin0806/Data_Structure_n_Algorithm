// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// Here it is also work for {0,0,0,1} and target 1

#include <bits/stdc++.h>
using namespace std;

int solve(int index, int target, vector<int> &num)
{
    if (index == 0)
    {
        if (target == 0 && num[index] == 0)
            return 2;
        if (target == 0 || target == num[index])
            return 1;
        else
            return 0;
    }

    // Exclude call
    int excl = solve(index - 1, target, num);

    // Include call
    int incl = 0;
    if (target - num[index] >= 0)
        incl = solve(index - 1, target - num[index], num);

    return incl + excl;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    int curr_index = num.size() - 1;

    return solve(curr_index, tar, num);
}
