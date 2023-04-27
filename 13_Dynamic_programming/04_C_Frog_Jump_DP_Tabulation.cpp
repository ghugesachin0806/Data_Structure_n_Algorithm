// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    // Memoization vector
    vector<int> DP(n + 1, -1);

    DP[0] = 0;
    if (n == 1)
        return 0;

    int temp1 = INT_MAX;
    int temp2 = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        temp1 = DP[i - 1] + abs(heights[i] - heights[i - 1]);

        if (i > 1)
            temp2 = DP[i - 2] + abs(heights[i] - heights[i - 2]);

        DP[i] = min(temp1, temp2);
    }

    return DP[n - 1];
}