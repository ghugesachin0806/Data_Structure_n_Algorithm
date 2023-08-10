// https://leetcode.com/problems/combinations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int start, int n, int k, vector<int> vect, vector<vector<int>> &ans)
    {
        if (vect.size() == k)
        {
            ans.push_back(vect);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            vect.push_back(i);
            soln(i + 1, n, k, vect, ans);
            vect.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> vect;

        int start = 1;
        soln(start, n, k, vect, ans);

        return ans;
    }
};