// Optimized way to find power of any number using recursion

#include <bits/stdc++.h>
using namespace std;

int pow(int n, int m)
{
    // Base case
    if (m == 1)
    {
        return n;
    }

    // Recursive relation
    int ans = pow(n, m / 2);

    // if m is even
    if (m % 2 == 0)
    {
        return ans * ans;
    }

    // if m is even
    else
    {
        return n * ans * ans;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << pow(n, m);
}