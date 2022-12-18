#include <bits/stdc++.h>
using namespace std;

class animal
{

private:
    int space;

public:
    int health;
    // class member function
    void print_public()
    {
        cout << health << endl;
    }

    // Getter_function

    int get_space()
    {
        return space;
    }

    // Setter_function

    void set_space(int s)
    {
        space = s;
    }

    // destructor

    ~animal()
    {
        cout << "I'm cout of the scope now : health :  " << health << endl;
    }
};

int main()
{
    animal dog;
    dog.health = 100;
    dog.set_space(200);

    animal horse;
    horse.health = 300;
    horse.set_space(400);

    animal *cat = new animal;
    cat->health = 500;
    cat->set_space(600);

    // static objects are destructed automatically in reverse order of object creation

    delete cat; // dynamic obects have to be destructed manually
}

// I'm cout of the scope now : health :  500
// I'm cout of the scope now : health :  300
// I'm cout of the scope now : health :  100