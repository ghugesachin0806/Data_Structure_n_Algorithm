// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <bits/stdc++.h>
using namespace std;

// Given type of questions have relation as follow
// f(n) = (k-1)*f(n-1) + (k-1) * f(n-2)

#define MOD 1000000007

class Solution
{
public:
    long long solve(int n, int k)
    {
        // Memoization vector
        vector<long long> DP(n + 1, -1);

        DP[1] = k;
        DP[2] = k * k;

        for (int i = 3; i <= n; i++)
        {
            DP[i] = (((k - 1) * DP[i - 1]) % MOD + ((k - 1) * DP[i - 2]) % MOD) % MOD;
        }

        return DP[n] % MOD;
    }
    long long countWays(int n, int k)
    {
        // code here

        return solve(n, k) % MOD;
    }
};