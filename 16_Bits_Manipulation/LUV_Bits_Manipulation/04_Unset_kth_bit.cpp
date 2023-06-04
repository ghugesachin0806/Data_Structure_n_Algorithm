// no link

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int replaceBit(int n, int k)
    {
        // code here.
        int mask = (~(1 << k));

        return (n & mask);
    }
};
