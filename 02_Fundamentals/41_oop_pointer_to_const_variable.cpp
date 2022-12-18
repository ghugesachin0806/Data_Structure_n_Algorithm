#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declare integer variable
    int x = 7;
    int y = 10;

    const int *ptr = &x; // here x become constant variable for pointer only

    cout << " \n The initial value of ptr:" << *ptr;
    cout << " \n The value of x: " << x;

    x = x + 10;
    cout << " \n The latest value of x: " << x;
    cout << " \n The latest value of ptr:" << *ptr;

    // *ptr = 15 <---- It is invalid; we cannot directly assign a value to the ptr variable

    ptr = &y; //  here ptr variable pointing to the non const address 'y'

    cout << " \n The value of y: " << y;
    cout << " \n The value of ptr:" << *ptr;
    return 0;
}