// https://www.codingninjas.com/codestudio/problems/square-root-decimal_1095655

#include <bits/stdc++.h>
using namespace std;

double solve(long long n, int d, int target)
{
    int i = 0;
    double factor = 1;

    double temp = n;
    while (i < d)
    {
        factor = factor / 10;
        while ((temp + factor) * (temp + factor) <= target)
        {
            temp += factor;
        }
        i++;
    }
    return temp;
}

double squareRoot(long long n, int d)
{
    long long start = 0;
    long long end = n;
    long long temp = 0;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (mid * mid <= n)
        {
            temp = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return solve(temp, d, n);
}