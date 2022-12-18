#include <bits/stdc++.h>
using namespace std;

// C++ program to show that we can access a global variable
// using scope resolution operator :: when there is a local variable with same name

int x = 100; // Global x

int main()
{
    int x = 10; // Local x
    cout << "Value of global x is " << ::x;
    cout << "\nValue of local x is " << x;
    return 0;
}

// Value of global x is 100
// Value of local x is 10