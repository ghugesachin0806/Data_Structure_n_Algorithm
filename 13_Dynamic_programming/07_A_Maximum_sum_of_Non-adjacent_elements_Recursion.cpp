// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &nums)
{
    if (index < 0)
        return 0;
    if (index == 0)
        return nums[0];

    // current element Exclude call
    int excl = solve(index - 1, nums) + 0;

    // current element Include call
    int incl = solve(index - 2, nums) + nums[index];

    return max(excl, incl);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    int index = nums.size() - 1;

    return solve(index, nums);
}