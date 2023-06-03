// https://practice.geeksforgeeks.org/problems/set-bits0143/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here

        // int cnt = 0;
        // while (N != 0)
        // {
        //     if (N & 1 == 1)
        //         cnt++;
        //     N = N >> 1;
        // }
        // return cnt;

        // slightly optimal solution

        int cnt = 0;

        while (N != 0)
        {
            cnt++;
            N = N & (N - 1);
        }

        return cnt;
    }
};