// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Below question have relation as follow
//  F(n) = (n-1) * {F(n-1)+F(n-2)}
long long int solve(int n)
{
    // Base cases
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    long long int ans = ((n - 1) * (solve(n - 1) + solve(n - 2)) % MOD) % MOD;
}

long long int countDerangements(int n)
{
    // Write your code here.
    return solve(n);
}