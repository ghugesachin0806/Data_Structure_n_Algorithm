// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int &x, int &y, int &z)
    {
        if (n < 0)
            return INT_MIN;
        if (n == 0)
            return 0;

        int temp1 = solve(n - x, x, y, z) + 1;
        int temp2 = solve(n - y, x, y, z) + 1;
        int temp3 = solve(n - z, x, y, z) + 1;

        return max(temp1, max(temp2, temp3));
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        int cnt = 0;
        int temp = solve(n, x, y, z);

        if (temp < 0)
            return 0;

        return temp;
    }
};