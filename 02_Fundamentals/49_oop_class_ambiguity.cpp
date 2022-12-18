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
    void speak()
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
    // h1.speak(); <--- will through an error because two parent classes have same name function

    // Below we solved the ambiguity using scope resolution operator
    h1.animal::speak();
    h1.bird::speak();
}

// I'm speaking
// I'm barking