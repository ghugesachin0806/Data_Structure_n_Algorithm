// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int index, vector<int> vect, vector<vector<int>> &ans)
    {
        if (index >= vect.size())
        {
            ans.push_back(vect);
            return;
        }

        for (int i = index; i < vect.size(); i++)
        {
            swap(vect[index], vect[i]);
            soln(index + 1, vect, ans);
            swap(vect[index], vect[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        int index = 0;
        soln(index, nums, ans);

        return ans;
    }
};