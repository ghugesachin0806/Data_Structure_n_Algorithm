// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here

        // return n & (1 << k); <--- one line answer

        int mask = 1;

        int check = n & (mask << k);

        if (check == 0)
            return false;
        else
            return true;
    }
};