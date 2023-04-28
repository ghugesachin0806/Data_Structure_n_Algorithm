// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int n, vector<int> &nums)
    {
        if (index > n)
            return 0;
        if (index == n)
            return nums[index];

        // Exclude call
        int excl = solve(index + 1, n, nums);

        // Include call
        int incl = solve(index + 2, n, nums) + nums[index];

        return max(excl, incl);
    }
    int rob(vector<int> &nums)
    {
        // code here
        int n = nums.size() - 1;
        int index = 0;
        return solve(index, n, nums);
    }
};