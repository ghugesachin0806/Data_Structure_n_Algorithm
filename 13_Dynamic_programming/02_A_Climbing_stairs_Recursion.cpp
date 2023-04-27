// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int n_stairs)
    {
        // Base case
        if (n == n_stairs)
            return 1;
        if (n > n_stairs)
            return 0;

        // Recursive call
        return solve(n + 1, n_stairs) + solve(n + 2, n_stairs);
    }
    int climbStairs(int n)
    {
        int intial_stair = 0;
        int total_stairs = n;
        
        return solve(intial_stair, total_stairs);
    }
};