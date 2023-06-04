// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();

        int max_bit_num = (1 << n); // <-- total number of subsets possible of size 'n' are 2^n.

        vector<vector<int>> ans;

        for (int i = 0; i < max_bit_num; i++)
        {
            vector<int> vect;

            int ptr = i;
            int cnt = 0;

            while (ptr != 0)
            {
                if ((ptr & 1) == 1)
                    vect.push_back(nums[cnt]);
                ptr = ptr >> 1;
                cnt++;
            }
            ans.push_back(vect);
        }

        return ans;
    }
};