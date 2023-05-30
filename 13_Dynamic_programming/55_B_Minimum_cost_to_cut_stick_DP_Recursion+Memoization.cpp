// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int ptr1, int ptr2, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (ptr1 > ptr2)
            return 0;

        if (dp[ptr1][ptr2] != -1)
            return dp[ptr1][ptr2];

        int mini = INT_MAX;

        for (int i = ptr1; i <= ptr2; i++)
        {
            int temp = solve(ptr1, i - 1, cuts, dp) + solve(i + 1, ptr2, cuts, dp) + (cuts[ptr2 + 1] - cuts[ptr1 - 1]);
            mini = min(mini, temp);
        }
        return dp[ptr1][ptr2] = mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        int ptr1 = 1;
        int ptr2 = cuts.size() - 2;

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));

        return solve(ptr1, ptr2, cuts, dp);
    }
};