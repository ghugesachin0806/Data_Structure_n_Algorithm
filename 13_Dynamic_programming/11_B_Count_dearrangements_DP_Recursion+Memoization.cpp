// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Below question have relation as follow
//  F(n) = (n-1) * {F(n-1)+F(n-2)}
long long int solve(int n, vector<long long int> &DP)
{
    // Base cases
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (DP[n] != -1)
        return DP[n];

    DP[n] = ((n - 1) * (solve(n - 1, DP) + solve(n - 2, DP)) % MOD) % MOD;

    return DP[n];
}

long long int countDerangements(int n)
{
    // Write your code here.

    // Memoization vector
    vector<long long int> DP(n + 1, -1);
    return solve(n, DP);
}