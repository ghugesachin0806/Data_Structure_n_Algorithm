// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr, int total_stairs, vector<int> &cost)
    {
        if (curr < 0)
            return 0;
        if (curr == 0)
            return cost[0];

        int min_cost = min(solve(curr - 1, total_stairs, cost), solve(curr - 2, total_stairs, cost));
        min_cost = min_cost + cost[curr];

        return min_cost;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int intial_stair = n;
        int total_stairs = n;

        int min_cost = min(solve(n - 1, total_stairs, cost), solve(n - 2, total_stairs, cost));

        return min_cost;
    }
};