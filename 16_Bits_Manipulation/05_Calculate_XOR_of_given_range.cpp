// https://practice.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findXOR(int a, int b)
    {
        // complete the function here
        // Code here
        int ans;

        if (b % 4 == 0)
            ans = b;
        else if (b % 4 == 1)
            ans = 1;
        else if (b % 4 == 2)
            ans = b + 1;
        else
            ans = 0;

        a = a - 1;

        if (a >= 0)
        {
            int temp;

            if (a % 4 == 0)
                temp = a;
            else if (a % 4 == 1)
                temp = 1;
            else if (a % 4 == 2)
                temp = a + 1;
            else
                temp = 0;

            ans = ans ^ temp;
        }

        return ans;
    }
};