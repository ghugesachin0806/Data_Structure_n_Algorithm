// Note -> The assignment operator('=') and the default copy constructor make a shallow copy

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
        name = new char[100];
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

    // Below shallow copy will be created due to default copy constructor

    animal cat(dog); // or cat=dog ;
    cat.print_me();

    cat.name[0] = 'H';
    cat.print_me();

    ////////////////////////////////

    dog.print_me();
}

// [ sachin 100  200 ]

// [ sachin 100  200 ]

// [ Hachin 100  200 ]

// [ Hachin 100  200 ]