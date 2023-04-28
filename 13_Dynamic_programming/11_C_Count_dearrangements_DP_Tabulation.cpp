// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Below question have relation as follow
//  F(n) = (n-1) * {F(n-1)+F(n-2)}
long long int solve(int n)
{
    // Memoization vector
    vector<long long int> DP(n + 1, -1);

    DP[1] = 0;
    DP[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        DP[i] = (i - 1) * (DP[i - 1] + DP[i - 2]) % MOD;
    }

    return DP[n];
}

long long int countDerangements(int n)
{
    // Write your code here.
    return solve(n);
}