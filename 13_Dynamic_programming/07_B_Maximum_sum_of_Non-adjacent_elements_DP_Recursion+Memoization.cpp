// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &nums, vector<int> &DP)
{
    if (index < 0)
        return 0;
    if (index == 0)
        return nums[0];

    if (DP[index] != INT_MIN)
        return DP[index];
    // current element Exclude call
    int excl = solve(index - 1, nums, DP) + 0;

    // current element Include call
    int incl = solve(index - 2, nums, DP) + nums[index];

    DP[index] = max(excl, incl);
    return DP[index];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    // Memoization vector
    vector<int> DP(nums.size() + 1, INT_MIN);

    int index = nums.size() - 1;

    return solve(index, nums, DP);
}