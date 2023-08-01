// https://leetcode.com/problems/combinations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int n, int k, int cnt, vector<int> vect, vector<vector<int>> &ans)
    {
        if (k == 0)
        {
            ans.push_back(vect);
            return;
        }
        if (cnt == n + 1)
            return;

        // exclude call
        soln(n, k, cnt + 1, vect, ans);

        // include call
        vect.push_back(cnt);
        soln(n, k - 1, cnt + 1, vect, ans);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> vect;

        soln(n, k, 1, vect, ans);

        return ans;
    }
};