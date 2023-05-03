// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// ################### answer is corect ###########################

// It only works for all the nums[i]>0
// but it is not working  for {0,0,0,1} and target = 1 ,
// we are traversing from back to start. so zeros are not get included in that.

#include <bits/stdc++.h>
using namespace std;

int solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (index < 0 || target < 0)
        return 0;

    if (dp[index][target] != -1)
        return dp[index][target];

    // Include call
    int incl = solve(index - 1, target - nums[index], nums, dp);

    // Exclude call
    int excl = solve(index - 1, target, nums, dp);

    dp[index][target] = excl + incl;

    return dp[index][target];
}

int findWays(vector<int> &nums, int target)
{
    // code here
    int curr_index = nums.size() - 1;

    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    return solve(curr_index, target, nums, dp);
}