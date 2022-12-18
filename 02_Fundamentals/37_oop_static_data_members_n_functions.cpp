#include <bits/stdc++.h>
using namespace std;

class animal
{

private:
    int space;

public:
    int health;
    // static data member
    static int count;

    // constructor
    animal()
    {
        count++;
    }

    // static member function
    // static member functions can access only static members of a class

    static void count_me()
    {
        cout << "Total count : " << count << endl;
    }

    static void modify_me(int n)
    {
        cout << "Modify count me " << count + n << endl;
    }

    // class member function
    void print_public()
    {
        cout << "health : " << health << endl;
        cout << "space : " << space << endl;
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
};

int animal::count = 0;

int main()
{
    cout << "Initial count : " << animal::count << endl;

    animal cat;
    cout << "NEXT count : " << animal::count << endl;

    animal horse;
    animal chita;

    animal::count_me();

    animal::count = 90;
    animal::count_me();

    animal::modify_me(30);
}

// Initial count : 0
// NEXT count : 1
// Total count : 3
// Total count : 90
// Modify count me 120