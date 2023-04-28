// https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums, int n)
    {
        int prev1 = nums[index];
        if (n - index == 1)
            return prev1;
        int prev2 = max(nums[index], nums[index + 1]);

        for (int i = index + 2; i < n; i++)
        {
            // Exclude call
            int excl = prev2 + 0;
            // Include call
            int incl = prev1 + nums[i];

            int curr = max(excl, incl);

            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        // Include first element and Exclude the Last element
        int n1 = nums.size() - 1;
        int index1 = 0;
        int temp1 = solve(index1, nums, n1);

        // Exclude first element and Include the Last element
        int n2 = nums.size();
        int index2 = 1;
        int temp2 = solve(index2, nums, n2);

        return max(temp1, temp2);
    }
};