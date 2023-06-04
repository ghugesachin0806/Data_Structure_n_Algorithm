#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << INT_MAX << endl;

    // In signed int 1 MSB bit is reserved for the sign of number
    int a = (1LL << 31) - 1; // 1LL ---> long long = 1
    cout << a << endl;

    // There is no bit reserved in unsigned int, so all 32-bits are used
    unsigned int b = (1LL << 32) - 1;
    cout << b << endl;
}

// 2147483647
// 2147483647
// 4294967295