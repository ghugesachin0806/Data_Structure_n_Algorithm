// https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev1 = nums[0];
        if (nums.size() == 1)
            return prev1;

        int prev2 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            // Exclusive call
            int excl = prev2 + 0;

            // Inclusive call
            int incl = prev1 + nums[i];

            int curr = max(excl, incl);

            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};