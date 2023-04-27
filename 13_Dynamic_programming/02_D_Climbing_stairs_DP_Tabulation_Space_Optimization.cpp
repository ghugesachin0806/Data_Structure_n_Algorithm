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

        // Assign the values to Base case
        // if n == base values return it.
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // Declare the required variables
        int curr;
        int prev1 = 2;
        int prev2 = 1;

        // Here we use count fron nth steps towards the 0th step
        for (int i = n - 3; i >= 0; i--)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};