// https://leetcode.com/problems/fibonacci-number/description/

// Approach II ---> Tabulation (Bottom-Up Approach)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        // ---> Step I
        // Create Memoization vector
        vector<int> DP(n + 1, -1);

        // ---> Step II
        // Assign the values to Base case
        // if n == base values return it.
        DP[0] = 0;
        if (n == 0)
            return DP[0];

        DP[1] = 1;

        // Step IV
        // Run the 'for loop' from 2 to n
        for (int i = 2; i <= n; i++)
        {
            DP[i] = DP[i - 1] + DP[i - 2];
        }

        return DP[n];
    }
};

// Time complexity ---> O(N)
// Space complexity ---> O(N)