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
        if (n == 1)
            return k;

        if (n == 2)
            return k * k;

        // last two posts have same colour
        long long last_same = ((k - 1) * solve(n - 2, k)) % MOD;

        // last two posts have different color
        long long last_differ = ((k - 1) * solve(n - 1, k)) % MOD;

        return (last_same + last_differ) % MOD;
    }
    long long countWays(int n, int k)
    {
        // code here
        return solve(n, k) % MOD;
    }
};