// https://leetcode.com/problems/fibonacci-number/description/

// Approach I ---> Recursion + Memoization (Top-Down Approach)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> &DP)
    {
        //---> Step I
        // Base condition
        if (n == 1 || n == 0)
            return n;

        //---> Step II
        // if value of sub_problem present,then return it
        if (DP[n] != -1)
            return DP[n];

        //---> Step III
        // Recursive call and store the sub_problem value
        DP[n] = solve(n - 1, DP) + solve(n - 2, DP);
        return DP[n];
    }
    int fib(int n)
    {
        // Memoization vector
        vector<int> DP(n + 1, -1);

        return solve(n, DP);
    }
};

// Time complexity ---> O(N)
// Space complexity ---> O(N)