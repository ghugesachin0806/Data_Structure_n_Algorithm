// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        // code here
        if (N < M)
            return -1;
        if (S < 6)
        {
            if (((S * M) % N) == 0)
                return (S * M) / N;
            else
                return (S * M) / N + 1;
        }
        else
        {
            if (6 * N >= 7 * M)
            {
                if (((S * M) % N) == 0)
                    return (S * M) / N;
                else
                    return (S * M) / N + 1;
            }
            else
                return -1;
        }
    }
};