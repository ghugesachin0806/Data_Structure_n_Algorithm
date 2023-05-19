// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int ans = 0;
        queue<pair<int, int>> week;
        queue<pair<int, int>> month;

        for (auto it : days)
        {
            // pop the expire dates
            while (!week.empty() && week.front().first + 7 <= it)
                week.pop();

            while (!month.empty() && month.front().first + 30 <= it)
                month.pop();

            // Push the current dates
            week.push(make_pair(it, ans + costs[1]));
            month.push(make_pair(it, ans + costs[2]));

            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }

        return ans;
    }
};