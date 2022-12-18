#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;
    // creating reference variable
    int &j = i;
    cout << i << endl;
    i++;
    cout << j << endl;
    j++;
    cout << i << endl;
}
// 5
// 6
// 7