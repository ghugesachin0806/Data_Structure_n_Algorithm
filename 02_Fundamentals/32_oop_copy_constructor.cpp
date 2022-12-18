#include <bits/stdc++.h>
using namespace std;

class animal
{

private:
    int space;
    int jump;

public:
    int health;
    int pow;

    // constructor
    animal()
    {
        cout << "I'm in class now " << endl;
    }

    // Copy constructor
    animal(animal &temp)
    {
        cout << "copy constructor called : " << endl;

        this->health = temp.health;
        this->pow = temp.pow;
    }

    void print_public()
    {
        cout << health << " " << pow << endl;
    }

    // Getter_function

    int get_space()
    {
        return space;
    }

    int get_jump()
    {
        return jump;
    }

    // Setter_function

    void set_space(int s)
    {
        space = s;
    }

    void set_jump(int j)
    {
        if (j > 20)
            jump = j;
        else
            jump = 0;
    }
};

int main()
{
    animal b1;
    b1.health = 589;
    b1.pow = 454;

    animal w1(b1); // or w1=b1;

    cout << w1.health << " " << w1.pow << endl;
}

// I'm in class now
// copy constructor called :
// 589 454