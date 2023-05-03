// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int sum, int &k, vector<int> &nums, bool flag)
    {
        if (index < 0)
        {
            if (sum == 0 && flag == false)
                return 1;
            else
                return 0;
        }

        // Exclude current Index
        int excl = 0;
        if (flag == true)
            excl = solve(index - 1, k, k, nums, true);
        // Include current index
        int incl = solve(index - 1, sum - nums[index], k, nums, false);

        if (sum == 0 && flag == false)
            return excl + incl + 1;

        return excl + incl;
    }
    int subarraySum(vector<int> &nums, int k)
    {
        int curr_index = nums.size() - 1;
        int sum = k;
        return solve(curr_index, sum, k, nums, true);
    }
};