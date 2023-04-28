#include <bits/stdc++.h>
using namespace std;

int fact(int m)   // Recursive funtion
{
    if (m == 1)        // Base condition
        return m;

    return m * fact(m - 1);  // recursive relation
}

int main()
{
    int n;
    cin >> n;
    int ans;
    ans = fact(n);
    cout << ans << endl;
}

// -> 6
// 720