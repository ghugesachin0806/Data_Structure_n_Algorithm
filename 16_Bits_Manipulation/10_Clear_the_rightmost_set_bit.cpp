#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 90;

    bitset<8> b1(n);
    cout << b1 << endl;

    int ans = (n & (n - 1));

    bitset<8> b2(ans);
    cout << b2 << endl;
}

// 01011010
// 01011000