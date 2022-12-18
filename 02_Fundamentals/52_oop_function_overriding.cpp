#include <bits/stdc++.h>
using namespace std;

class animal
{
public:
    int x;
    int y;

    void speak()
    {
        cout << "I'm speaking" << endl;
    }
};

class bird : public animal
{
public:
    void speak()
    {
        // Function overriding
        cout << "I'm barking" << endl;
    }
};

int main()
{
    bird b1;   // parent class
    animal a1; // child class

    b1.speak();
    a1.speak();
}

// I'm barking
// I'm speaking