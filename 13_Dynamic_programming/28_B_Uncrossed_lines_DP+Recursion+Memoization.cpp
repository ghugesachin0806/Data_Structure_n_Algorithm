// https://leetcode.com/problems/uncrossed-lines/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int nums1_ind, int nums2_ind, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (nums1_ind < 0 || nums2_ind < 0)
            return 0;

        if (dp[nums1_ind][nums2_ind] != -1)
            return dp[nums1_ind][nums2_ind];

        if (nums1[nums1_ind] == nums2[nums2_ind])
            dp[nums1_ind][nums2_ind] = (1 + solve(nums1_ind - 1, nums2_ind - 1, nums1, nums2, dp));
        else
            dp[nums1_ind][nums2_ind] = max(solve(nums1_ind - 1, nums2_ind, nums1, nums2, dp), solve(nums1_ind, nums2_ind - 1, nums1, nums2, dp));

        return dp[nums1_ind][nums2_ind];
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int nums1_ind = n1 - 1;
        int nums2_ind = n2 - 1;

        // Memoization Vector
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return solve(nums1_ind, nums2_ind, nums1, nums2, dp);
    }
};