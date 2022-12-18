#include <bits/stdc++.h>
using namespace std;

class ABC
{
public:
    // use const keyword to declare const data member
    const int A;

    // create class constructor
    // We can only assign values to const data members using intialization list shown below
    ABC(int y) : A(y)
    {
        // A = 90; //<--- Not allowed to assign value to const keyword (not allowed)
        cout << " The value of y: " << A << endl;
    }
};

int main()
{
    ABC obj(10); // here 'obj' is the object of class ABC
    cout << " The value of constant data member 'A' is: " << obj.A << endl;
    // obj.A = 5; // it shows an error.
    cout << obj.A << endl;
    return 0;
}

//  The value of y: 10
//  The value of constant data member 'A' is: 10
//  10