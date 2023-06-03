// https://practice.geeksforgeeks.org/problems/odd-or-even3618/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddEven(int N)
    {
        // Faster
        if ((N & 1) == 0) // if(N & 1 == 0) -----> Not work,include bracket
            return "even";
        else
            return "odd";

        // Slower
        // if (N % 2 == 0)
        //     return "even";
        // else
        //     return "odd";
    }
};