// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &days, vector<int> &costs)
    {
        if (index >= days.size())
            return 0;

        // 1 day pass
        int temp1 = costs[0] + solve(index + 1, days, costs);

        // 7 day pass
        int i = 0;
        for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
        {
            // i++
        }
        int temp7 = costs[1] + solve(i, days, costs);

        // 30 day pass
        int j = 0;
        for (j = index; j < days.size() && days[j] < days[index] + 30; j++)
        {
            // j++
        }
        int temp30 = costs[2] + solve(j, days, costs);

        return min(temp1, min(temp7, temp30));
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int curr_index = 0;
        return solve(curr_index, days, costs);
    }
};