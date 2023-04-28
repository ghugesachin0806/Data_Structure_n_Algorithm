// https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums, int n, vector<int> &DP)
    {
        if (index > n)
            return 0;

        if (index == n)
            return nums[index];

        if (DP[index] != -1)
            return DP[index];

        // Exclude call
        int excl = solve(index + 1, nums, n, DP) + 0;
        // Include call
        int incl = solve(index + 2, nums, n, DP) + nums[index];

        DP[index] = max(excl, incl);

        return DP[index];
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        // Include first element and Exclude the Last element

        vector<int> DP1(nums.size() + 1, -1); // Memoization array
        int n1 = nums.size() - 2;
        int index1 = 0;
        int temp1 = solve(index1, nums, n1, DP1);

        // Exclude first element and Include the Last element

        vector<int> DP2(nums.size() + 1, -1); // Memoization array
        int n2 = nums.size() - 1;
        int index2 = 1;
        int temp2 = solve(index2, nums, n2, DP2);

        return max(temp1, temp2);
    }
};