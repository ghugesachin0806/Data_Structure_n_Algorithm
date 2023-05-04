// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// ################### answer is corect ###########################

// It only works for all the nums[i]>0
// but it is not working  for {0,0,0,1} and target = 1 ,
// we are traversing from back to start. so zeros are not get included in that.

#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &nums, int target)
{
    // code here
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

    for (int i = 0; i < nums.size(); i++)
        dp[i][0] = 1;

    if (nums[0] <= target)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        for (int del = 0; del <= target; del++)
        {
            // Exclude call
            int excl = dp[i - 1][del];

            // Include call
            int incl = 0;
            if (del - nums[i] >= 0)
                incl = dp[i - 1][del - nums[i]];

            dp[i][del] = incl + excl;
        }
    }
    return dp[nums.size() - 1][target];
}