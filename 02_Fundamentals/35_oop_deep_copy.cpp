#include <bits/stdc++.h>
using namespace std;

class animal
{

private:
    int space;

public:
    int health;
    char *name;

    // Constructor
    animal()
    {
        cout << "I'm in constructor" << endl;

        name = new char[100];
    }

    // Copy constructor
    animal(animal &temp)
    {
        cout << "I'm in copy constructor" << endl;

        this->name = new char[100];
        strcpy(this->name, temp.name);

        this->health = temp.health;
        this->space = temp.space;
    }

    // Print_me function

    void print_me()
    {
        cout << "[ " << name << " " << health << " "
             << " " << space << " ]" << endl;
        cout << endl;
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

    void set_name(char name[])
    {
        strcpy(this->name, name);
    }
};

int main()
{
    animal dog;

    dog.health = 100;
    dog.set_space(200);
    char name[] = "sachin";
    dog.set_name(name);

    dog.print_me();

    /////////////////////////////////

    // Below deep-copy will be created due to newly created copy constructor

    animal cat(dog); // or cat=dog ;
    cat.print_me();

    cat.name[0] = 'H';
    cat.print_me();

    ////////////////////////////////

    dog.print_me();
}

// I'm in constructor
// [ sachin 100  200 ]

// I'm in copy constructor
// [ sachin 100  200 ]

// [ Hachin 100  200 ]

// [ sachin 100  200 ]