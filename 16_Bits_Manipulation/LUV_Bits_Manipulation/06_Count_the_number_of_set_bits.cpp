// https://practice.geeksforgeeks.org/problems/set-bits0143/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBits(int N)
    {
        // return the total set bits using inbuilt fuction

        // for int
        return __builtin_popcount(N);

        // for long long
        // return __builtin_popcountll(N);
    }
};