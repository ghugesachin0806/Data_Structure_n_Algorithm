#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    int A;
    int B;
    // create constructor of the class ABC
    ABC()
    {
        A = 10; // define a value to A
        B = 20;
    }

    void fun()
    {
        cout << A << " " << B << endl;
    }

    // constant member function
    void const_fun() const
    {
        cout << A << " " << B << endl;
    }
};
int main()
{
    // declare a constant object
    const ABC obj;
    cout << " The value of A: " << obj.A << endl;

    // obj.fun(); <-- Non-constant member functions not allowed to call by constant object
    obj.const_fun(); // <-- allowed to call only the  constant member functions of the class

    cout << " The value of A: " << obj.B << endl;
    // obj.A = 20; // It returns a compile time error
    return 0;
}