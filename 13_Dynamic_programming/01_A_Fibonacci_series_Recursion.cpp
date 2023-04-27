// https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

// Normal Recursion

class Solution
{
public:
    int solve(int n)
    {
        // Base condition
        if (n == 1 || n == 0)
            return n;

        // Recursive calls
        return (solve(n - 1) + solve(n - 2));
    }

    int fib(int n)
    {
        // code here
        return solve(n);
    }
};