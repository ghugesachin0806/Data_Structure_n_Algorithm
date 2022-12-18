#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declare the value of the const
    const int num = 25;

    // num = num + 10;  <- It will throw an error , because num is const variable

    int y = num * num;

    cout << num << endl;
    cout << y << endl;
    return 0;
}

// 25
// 625