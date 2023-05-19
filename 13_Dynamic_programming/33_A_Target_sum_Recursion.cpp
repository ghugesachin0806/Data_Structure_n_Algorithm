// https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums, int sum, int &target)
    {
        if (index >= nums.size())
        {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        // +ve sign
        int temp1 = solve(index + 1, nums, sum + nums[index], target);

        // -ve sign
        int temp2 = solve(index + 1, nums, sum - nums[index], target);

        return temp1 + temp2;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int curr_index = 0;
        int sum = 0;

        return solve(curr_index, nums, sum, target);
    }
};