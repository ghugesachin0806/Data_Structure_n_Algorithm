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

class bird
{
public:
    void bark()
    {
        cout << "I'm barking" << endl;
    }
};

// Multiple inheritance
class human : public animal, public bird
{
};

int main()
{
    human h1;
    h1.bark();
    h1.speak();
}

// I'm barking
// I'm speaking