#include <bits/stdc++.h>
using namespace std;

inline int getmax(int a, int b) // Like this inline function is created
{
    return ((a > b) ? a : b);
}

int main()
{
    int a, b;
    a = 10, b = 11;
    int ans;
    ans = getmax(a, b); // Here function is called , while compiling , the code of this function will get copied here instead passing argument
    cout << ans << endl;

    a += 3;
    b += 1;

    ans = getmax(a, b); // Here function is called , while compiling , the code of this function will get copied here instead passing argument
    cout << ans << endl;
}
// 11
// 13