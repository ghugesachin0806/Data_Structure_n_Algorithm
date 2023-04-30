// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <bits/stdc++.h>
using namespace std;

// Given type of questions have relation as follow
// f(n) = (k-1)*f(n-1) + (k-1) * f(n-2)

#define MOD 1000000007

class Solution
{
public:
    long long solve(int n, int k, vector<long long> &DP)
    {
        if (n == 1)
            return k;

        if (n == 2)
            return k * k;

        if (DP[n] != -1)
            return DP[n];

        // last two posts have same colour
        long long last_same = ((k - 1) * solve(n - 2, k, DP)) % MOD;

        // last two posts have different color
        long long last_differ = ((k - 1) * solve(n - 1, k, DP)) % MOD;

        DP[n] = (last_same + last_differ) % MOD;

        return DP[n];
    }
    long long countWays(int n, int k)
    {
        // code here

        // Memoization vector
        vector<long long> DP(n + 1, -1);

        return solve(n, k, DP) % MOD;
    }
};