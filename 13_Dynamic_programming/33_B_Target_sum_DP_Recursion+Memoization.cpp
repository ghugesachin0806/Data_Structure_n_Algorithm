// https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums, int sum, int &target, vector<vector<int>> &dp1, vector<vector<int>> &dp2)
    {
        if (index >= nums.size())
        {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        if (sum >= 0 && dp1[index][sum] != -1)
            return dp1[index][sum];
        if (sum < 0 && dp2[index][abs(sum)] != -1)
            return dp2[index][abs(sum)];

        // +ve sign
        int temp1 = solve(index + 1, nums, sum + nums[index], target, dp1, dp2);

        // -ve sign
        int temp2 = solve(index + 1, nums, sum - nums[index], target, dp1, dp2);

        if (sum >= 0)
            return dp1[index][sum] = temp1 + temp2;
        else
            return dp2[index][abs(sum)] = temp1 + temp2;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int curr_index = 0;
        int sum = 0;

        int temp_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp_sum = temp_sum + nums[i];
        }

        vector<vector<int>> dp1(nums.size() + 1, vector<int>(temp_sum + 1, -1));
        vector<vector<int>> dp2(nums.size() + 1, vector<int>(temp_sum + 1, -1));

        return solve(curr_index, nums, sum, target, dp1, dp2);
    }
};