// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr, int total_stairs, vector<int> &cost, vector<int> &DP)
    {
        if (curr < 0)
            return 0;
        if (curr == 0)
            return cost[0];

        if (DP[curr] != -1)
            return DP[curr];

        int min_cost = min(solve(curr - 1, total_stairs, cost, DP), solve(curr - 2, total_stairs, cost, DP));
        min_cost = min_cost + cost[curr];

        DP[curr] = min_cost;

        return min_cost;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int intial_stair = n;
        int total_stairs = n;

        //  Memoization vector
        vector<int> DP(n, -1);

        int min_cost = min(solve(n - 1, total_stairs, cost, DP), solve(n - 2, total_stairs, cost, DP));

        return min_cost;
    }
};