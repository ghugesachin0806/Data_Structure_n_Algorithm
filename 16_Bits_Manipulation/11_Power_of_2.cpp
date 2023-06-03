// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        // Your code here
        int ans = 1; // because '0' is not power of 2
        if (n > 0)
            ans = (n & (n - 1));

        if (ans == 0)
            return true;
        else
            return false;
    }
};