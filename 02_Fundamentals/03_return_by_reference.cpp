#include <bits/stdc++.h>
using namespace std;

int &fun1(int &a)
{
    a++;
    return a;
}

int main()
{
    int x = 10;
    cout << x << endl;
    cout << fun1(x) << endl;
    fun1(x) = 22; // Here we are assigning some value to function , It is achieved by return by reference
    cout << x << endl;
}
// 10
// 11
// 22