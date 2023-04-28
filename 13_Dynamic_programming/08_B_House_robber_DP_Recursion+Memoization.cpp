// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int n, vector<int> &nums, vector<int> &DP)
    {
        if (index > n)
            return 0;
        if (index == n)
            return nums[index];

        if (DP[index] != -1)
            return DP[index];

        // Exclude call
        int excl = solve(index + 1, n, nums, DP);

        // Include call
        int incl = solve(index + 2, n, nums, DP) + nums[index];

        DP[index] = max(excl, incl);

        return DP[index];
    }
    int rob(vector<int> &nums)
    {
        // code here

        // Memoization vector
        vector<int> DP(nums.size(), -1);

        int n = nums.size() - 1;
        int index = 0;
        return solve(index, n, nums, DP);
    }
};