#include <bits/stdc++.h>
using namespace std;

void ref(int &j)
{
    j++;
}
int main()
{
    int i = 5;
    cout << "Before " << i << endl;
    ref(i);
    cout << "After " << i << endl;
}
// Before 5
// After 6