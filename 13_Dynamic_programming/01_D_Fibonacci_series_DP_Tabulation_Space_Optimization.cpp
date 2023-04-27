// https://leetcode.com/problems/fibonacci-number/description/

// Approach III ---> Tabulation (Bottom-Up Approach) +Space_Optimization

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {

        // ---> Step I
        // Declare the required variables
        int curr;
        int prev1 = 1;
        int prev2 = 0;

        // Step II
        // Return the value for the base case
        if (n == 0)
            return prev2;

        // Step III
        // Run the 'for loop' from 2 to n
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

// Time complexity ---> O(N)
// Space complexity ---> O(1)