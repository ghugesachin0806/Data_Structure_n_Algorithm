// no link

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int toggle(int n, int k)
    {
        // code here.
        return (n ^ (1 << k));
    }
};