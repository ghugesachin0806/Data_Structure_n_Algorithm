#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 59;
    int k = 3; // 0-based indexing

    int mask = (1 << (k + 1));
    mask = mask - 1;
    mask = (~mask);

    int ans = (n & mask);

    bitset<8> b1(n);
    bitset<8> b2(ans);

    cout << b1 << endl;
    cout << b2 << endl;
}

// 00111011
// 00110000