// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int soln(int index, vector<int> &startTime, vector<int> &dp, vector<vector<int>> &vect)
    {
        if (index == startTime.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // non-pick current index
        int excl = soln(index + 1, startTime, dp, vect);

        // pick current index
        int newindex = lower_bound(startTime.begin(), startTime.end(), vect[index][1]) - startTime.begin();
        int incl = soln(newindex, startTime, dp, vect) + vect[index][2];

        return dp[index] = max(excl, incl);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {

        vector<vector<int>> vect;

        vector<int> dp(startTime.size(), -1);
        for (int i = 0; i < startTime.size(); i++)
        {
            vect.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(vect.begin(), vect.end());
        sort(startTime.begin(), startTime.end());

        return soln(0, startTime, dp, vect);
    }
};