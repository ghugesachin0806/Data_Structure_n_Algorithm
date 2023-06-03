#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 63;
    int k = 3;

    bitset<8> b1(n);
    cout << b1 << " :given number" << endl;

    int mask = 1;
    mask = ~(mask << k);
    bitset<8> b2(mask);
    cout << b2 << " :mask " << endl;

    int ans = (n & mask);
    bitset<8> b3(ans);
    cout << b3 << " :modified number" << endl;
}

// 00111111 :given number
// 11110111 :mask
// 00110111 :modified number