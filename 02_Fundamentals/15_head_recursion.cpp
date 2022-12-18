// For head recursion
// 1. Base condition
// 2. Recursive relation
// 3. Processing part
#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    // base condition
    if (n == 0)
    {
        return;
    }

    // recursive relation
    print(n - 1);

    // processing part
    cout << n << endl;
}

int main()
{
    int t;
    cin >> t;
    cout << endl;

    print(t);
}

// -> 5

// 1
// 2
// 3
// 4
// 5