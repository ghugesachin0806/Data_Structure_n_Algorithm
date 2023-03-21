// https://leetcode.com/problems/sqrtx/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int start = 0;
        int end = x;

        int temp = 0;

        while (start <= end)
        {
            long long int mid = start + (end - start) / 2;

            if (mid * mid <= x)
            {
                temp = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return temp;
    }
};