#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    int A;

    // Constructor
    ABC()
    {
        A = 90;
    }

    void print()
    {
        cout << "Value of A cube : " << A * A * A << endl;
    }

    // declare member function as constant using const keyword
    void print_me() const
    {
        cout << "Value of A square : " << A * A << endl;
    }

    // Below const functions are only allowed to read class data members, they are not allowed to change their values
    void fun() const
    {
        // A = 0; <--- it shows compile time error

        // Non-const functions not allowed to call from const-function
        //  print(); <--- it shows compile time error

        // Below function is allowed to call , because it is const-function
        print_me();

        cout << "Value of A : " << A << endl;
    }
};

int main()
{
    ABC obj;
    obj.fun();
    return 0;
}

// Value of A square : 8100
// Value of A : 90