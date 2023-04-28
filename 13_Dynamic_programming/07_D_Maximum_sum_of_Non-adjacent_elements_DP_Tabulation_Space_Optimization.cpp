// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int prev1 = nums[0];
    if (nums.size() == 1)
        return nums[0];
    int prev2 = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        // current element excluded
        int excl = prev2 + 0;
        // Current element included
        int incl = prev1 + nums[i];

        int curr = max(excl, incl);

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    return solve(nums);
}