// https://practice.geeksforgeeks.org/problems/set-kth-bit3724/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setKthBit(int N, int K)
    {
        // Write Your Code here
        return (N | (1 << K));
    }
};