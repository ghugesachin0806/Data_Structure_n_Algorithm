// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Below question have relation as follow
//  F(n) = (n-1) * {F(n-1)+F(n-2)}
long long int solve(int n)
{

    long long int prev1 = 0;
    long long int prev2 = 1;
    for (long long int i = 3; i <= n; i++)
    {
        long long int curr = ((i - 1) * (prev1 + prev2) % MOD) % MOD;

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

long long int countDerangements(int n)
{
    // Write your code here.
    return solve(n);
}