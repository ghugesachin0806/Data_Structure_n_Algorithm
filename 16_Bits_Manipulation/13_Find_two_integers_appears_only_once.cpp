// https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int allxor = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            allxor = allxor ^ nums[i];
        }

        // cnt = right most set bit index
        int cnt = 0;
        int temp = allxor;

        while (1)
        {
            if (temp & 1 == 1)
                break;

            temp = temp >> 1;
            cnt++;
        }

        int temp1 = 0;
        int temp2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int differ_bit = (nums[i] >> cnt) & 1;
            if (differ_bit)
                temp1 = temp1 ^ nums[i];
            else
                temp2 = temp2 ^ nums[i];
        }

        vector<int> ans;
        ans.push_back(temp1);
        ans.push_back(temp2);

        return ans;
    }
};