// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int cnt, vector<int> vect, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (cnt == nums.size())
        {
            ans.push_back(vect);
            return;
        }

        // exclude call
        soln(cnt + 1, vect, nums, ans);

        // include call
        vect.push_back(nums[cnt]);
        soln(cnt + 1, vect, nums, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> vect;
        soln(0, vect, nums, ans);

        return ans;
    }
};