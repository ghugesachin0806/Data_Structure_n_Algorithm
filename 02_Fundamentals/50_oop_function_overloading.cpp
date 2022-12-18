#include <bits/stdc++.h>
using namespace std;

class animal
{
public:
    int x;
    int y;

    void speak()
    {
        cout << "I'm speaking " << endl;
    }

    // Function overloading using different types of arguments
    void speak(int n)
    {
        cout << "I'm speaking " << n << endl;
    }
    void speak(double x)
    {
        cout << "I'm speaking " << x << endl;
    }

    // Function overloading using differ in sequence of atypes of arguments
    void speak(int n, float x)
    {
        cout << "I'm speaking " << n << " : " << x << endl;
    }

    void speak(float x, int n)
    {
        cout << "I'm speaking " << n << " : " << x << endl;
    }
};

int main()
{
    animal dog;

    dog.speak();
    dog.speak(2);
    dog.speak(6.3);
    dog.speak(2, 6.3);
    dog.speak(6.3, 2);
}

// I'm speaking
// I'm speaking 2
// I'm speaking 6.3
// I'm speaking 2 : 6.3
// I'm speaking 2 : 6.3