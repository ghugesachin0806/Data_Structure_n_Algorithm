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
        long long prev1 = k;
        if (n == 1)
            return prev1;

        long long prev2 = k * k;

        for (int i = 3; i <= n; i++)
        {
            long long curr = (((k - 1) * prev1) % MOD + ((k - 1) * prev2) % MOD) % MOD;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
    long long countWays(int n, int k)
    {
        // code here

        return solve(n, k) % MOD;
    }
};