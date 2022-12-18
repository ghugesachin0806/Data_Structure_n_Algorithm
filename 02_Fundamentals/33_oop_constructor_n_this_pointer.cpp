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

    // Constructor overloading and (this pointer)
    animal()
    {
        health = 1;
        pow = 2;
        space = 3;
        jump = 5;
    }
    animal(int health)
    {
        this->health = health;
        space = 10;
        jump = 8;

        cout << "Address of current object : " << this << endl;
    }

    animal(int health, int pow)
    {
        this->health = health;
        this->pow = pow;
        space = 510;
        jump = 568;

        cout << "Address of current object : " << this << endl;
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

    void set_space(int space)
    {
        this->space = space; // this pointer is used
    }

    void set_jump(int jump)
    {
        if (jump > 20)
            this->jump = jump; // this pointer is used
        else
            this->jump = 0;
    }
};

int main()
{
    animal w1(45);
    w1.set_jump(200);
    w1.set_space(100);

    cout << "Address of object : " << &w1 << endl;
    cout << w1.health << endl;

    cout << "Jump : " << w1.get_jump() << endl;
    cout << "Space : " << w1.get_space() << endl;

    ///////////////////////////////////////////////////////////

    animal b1(369, 528);

    cout << "Address of object : " << &b1 << endl;

    cout << b1.get_jump() << " " << b1.get_space() << endl;
    cout << b1.health << " " << b1.pow << endl;
}

// Address of current object : 0xe947ff940
// Address of object : 0xe947ff940
// 45
// Jump : 200
// Space : 100
// Address of current object : 0xe947ff930
// Address of object : 0xe947ff930
// 568 510
// 369 528