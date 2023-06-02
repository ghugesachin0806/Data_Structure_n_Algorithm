// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code here
        sort(a.begin(), a.end());

        int ptr1 = 0;
        int ptr2 = m - 1;

        long long differ = INT_MAX;

        while (ptr2 != a.size())
        {
            differ = min(differ, a[ptr2] - a[ptr1]);
            ptr2++;
            ptr1++;
        }

        return differ;
    }
};