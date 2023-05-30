// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int prev, vector<int> &nums)
    {
        if (index == nums.size())
            return 0;

        if (prev == -1 || nums[index] > nums[prev])
        {
            // Include call
            int incl = solve(index + 1, index, nums) + 1;

            // Exclude call
            int excl = solve(index + 1, prev, nums) + 0;

            return max(incl, excl);
        }
        else
        {
            // Exclude call
            return solve(index + 1, prev, nums);
        }
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int prev = -1;

        return solve(0, prev, nums);
    }
};