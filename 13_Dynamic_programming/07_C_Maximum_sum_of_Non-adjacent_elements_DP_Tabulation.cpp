// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    vector<int> DP(nums.size() + 1, INT_MIN);

    DP[0] = nums[0];
    if (nums.size() == 1)
        return nums[0];
    DP[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        // current element excluded
        int excl = DP[i - 1] + 0;
        // Current element included
        int incl = DP[i - 2] + nums[i];

        DP[i] = max(excl, incl);
    }

    return DP[nums.size() - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    return solve(nums);
}