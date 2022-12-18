#include <bits/stdc++.h>
using namespace std;

class test
{
    int a;
    int b;

public:
    test(int i, int j) : a(i), b(j) // Initialization list syntax
    {
        cout << "value of a : " << a << endl;
        cout << "value of b : " << b << endl;
    }
};

class exam
{
    int a;
    int b;

public:
    exam(int i, int j) : a(i), b(j + i) // Initialization list syntax
    {
        cout << "value of a : " << a << endl;
        cout << "value of b : " << b << endl;
    }
};

int main()
{
    test t1(90, 100);

    exam e1(100, 200);
}

// value of a : 90
// value of b : 100

// value of a : 100
// value of b : 300