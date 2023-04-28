// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int &x, int &y, int &z)
    {
        // Memoization vector
        vector<int> DP(n + 1, -1);

        DP[0] = 0;
        if (n == 0)
            return 0;

        for (int i = 1; i <= n; i++)
        {
            int temp1 = INT_MIN;
            int temp2 = INT_MIN;
            int temp3 = INT_MIN;

            if (i - x >= 0)
                temp1 = DP[i - x] + 1;
            if (i - y >= 0)
                temp2 = DP[i - y] + 1;
            if (i - z >= 0)
                temp3 = DP[i - z] + 1;

            DP[i] = max(temp1, max(temp2, temp3));
        }

        return DP[n];
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here

        int temp = solve(n, x, y, z);

        if (temp < 0)
            return 0;
            
        return temp;
    }
};