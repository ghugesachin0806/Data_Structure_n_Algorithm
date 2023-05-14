// https://leetcode.com/problems/perfect-squares/

// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int target)
    {
        if (target == 0)
            return 0;

        int temp_ans = target;
        for (int i = 1; i * i <= target; i++)
        {
            temp_ans = min(temp_ans, solve(target - i * i) + 1);
        }

        return temp_ans;
    }
    int numSquares(int n)
    {
        return solve(n);
    }
};