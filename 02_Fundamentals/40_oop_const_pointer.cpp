#include <bits/stdc++.h>
using namespace std;

int main()
{

    // declaration of the integer variables
    int x = 10;
    int y = 20;

    // use const keyword to make constant pointer
    int *const ptr = &x; //  const integer ptr variable point address to the variable x

    // ptr = &y; <---- now ptr cannot changed their address

    *ptr = 15; // ptr can only change the value

    cout << " The value of x: " << x << endl;
    cout << " The value of ptr: " << *ptr << endl;
}

//  The value of x: 15
//  The value of ptr: 15