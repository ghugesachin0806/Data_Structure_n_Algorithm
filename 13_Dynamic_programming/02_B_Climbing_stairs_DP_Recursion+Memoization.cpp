// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int n_stairs, vector<int> &DP)
    {
        // Base case
        if (n == n_stairs)
            return 1;
        if (n > n_stairs)
            return 0;

        // Check in the DP if the value is present
        if (DP[n] != -1)
            return DP[n];

        // Recursive call
        DP[n] = solve(n + 1, n_stairs, DP) + solve(n + 2, n_stairs, DP);
        return DP[n];
    }
    int climbStairs(int n)
    {
        // Memoization vector
        vector<int> DP(n + 1, -1);

        int intial_stair = 0;
        int total_stairs = n;

        return solve(intial_stair, total_stairs, DP);
    }
};