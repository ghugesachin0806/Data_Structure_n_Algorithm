// https://leetcode.com/problems/fair-distribution-of-cookies/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int index, int &k, int &ans, vector<int> vect, vector<int> &cookies)
    {
        if (index == cookies.size())
        {
            int temp = INT_MIN;
            for (auto it : vect)
            {
                temp = max(temp, it);
            }
            if (temp < ans)
                ans = temp;

            return;
        }

        for (int i = 0; i < k; i++)
        {
            vect[i] += cookies[index];

            if (vect[i] <= ans) // Runtime checking
                soln(index + 1, k, ans, vect, cookies);

            vect[i] -= cookies[index];
        }
    }
    int distributeCookies(vector<int> &cookies, int k)
    {

        vector<int> vect(k, 0);

        int index = 0;
        int ans = INT_MAX;

        soln(index, k, ans, vect, cookies);

        return ans;
    }
};