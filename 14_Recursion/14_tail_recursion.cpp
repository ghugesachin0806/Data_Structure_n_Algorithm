// For tail recursion
// 1. Base condition
// 2. Processing part
// 3. Recursive relation
#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    // base condition
    if (n == 0)
    {
        return;
    }

    // processing part
    cout << n << endl;

    // recursive relation
    print(n - 1);
}

int main()
{
    int t;
    cin >> t;
    cout << endl;

    print(t);
}

// -> 5

// 5
// 4
// 3
// 2
// 1