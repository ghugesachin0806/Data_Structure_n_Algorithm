// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    // Assign the values to Base case
    // if n == base values return it

    int prev1 = 0;
    if (n == 1)
        return 0;

    int prev2 = 0;

    int temp1 = INT_MAX;
    int temp2 = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        temp1 = prev1 + abs(heights[i] - heights[i - 1]);

        if (i > 1)
            temp2 = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(temp1, temp2);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}