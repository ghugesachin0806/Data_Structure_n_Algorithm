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
    animal a;

    // Accessing directly public data members of class are allowed
    a.health = 80;
    a.pow = 100;

    cout << "Health : " << a.health << endl;
    cout << "Power: " << a.pow << endl;

    // Accessing directly public member function is allowed
    a.print_public();

    // Accessing directly private data members of class are not allowed
    // a.space =100; <--- Invalid
    // a.jump =90;   <--- Invalid

    a.set_jump(50);
    a.set_space(100);

    cout << "Jump : " << a.get_jump() << endl;
    cout << "Space : " << a.get_space() << endl;

    // Read padding and greedy alignment for below code is important

    cout << "size of class animal obeject is : " << sizeof(a) << endl;
}

// Health : 80
// Power: 100
// 80 100
// Jump : 50
// Space : 100
// size of class animal obeject is : 16