// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // Memoization vector
        vector<int> DP(n + 1, -1);

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        DP[n - 1] = 1;
        DP[n - 2] = 2;

        // Here we use count fron nth steps towards the 0th step
        for (int i = n - 3; i >= 0; i--)
        {
            DP[i] = DP[i + 1] + DP[i + 2];
        }

        return DP[0];
    }
};