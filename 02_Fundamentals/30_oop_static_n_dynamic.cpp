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

    // Constructor
    animal(int i = 0, int j = 0)
    {
        this->health = i;
        this->space = j;
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
    // Static allocation for object
    animal a1;

    a1.health = 80;
    a1.set_jump(100);

    cout << "Health a1 : " << a1.health << endl;
    cout << "Jump a1 : " << a1.get_jump() << endl;

    // dynamic allocation for object
    animal *b1 = new animal(100, 200); // animal *b1 = new animal;

    cout << "Health of b1 : " << (*b1).health << endl;
    cout << "Space of b1 : " << (*b1).get_space() << endl;

    // One way
    (*b1).health = 120;
    (*b1).set_space(140);

    cout << "Health of b1 : " << (*b1).health << endl;
    cout << "Space of b1 : " << (*b1).get_space() << endl;

    // second way
    b1->pow = 160;
    b1->set_jump(190);

    cout << "Pow of b1 : " << b1->pow << endl;
    cout << "Jump of b1 : " << b1->get_jump() << endl;
}

// Health a1 : 80
// Jump a1 : 100

// Health of b1 : 100
// Space of b1 : 200

// Health of b1 : 120
// Space of b1 : 140

// Pow of b1 : 160
// Jump of b1 : 190