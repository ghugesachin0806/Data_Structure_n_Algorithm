// If we write any constructor in class , then default constructor will not be there anymore .
// Every class has default copy constructor , which will be not there if we write another copy constructor .

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

    // default constructor

    animal()
    {
        jump = 10;
        pow = 90;
        cout << "Hello constructor" << endl;
    }

    // Parametrized constructor

    animal(int a, int b)
    {
        cout << "Hello parametrized constructor" << endl;
        space = a;
        health = b;
    }
    // class member function
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

    // destructor

    ~animal()
    {
        cout << "I'm cout of the scope now " << endl;
    }
};

int main()
{

    // 1. Default constructors

    cout << "hello main" << endl;

    animal a1; // statically created
    cout << a1.get_jump() << " " << a1.pow << endl;

    cout << "hello main" << endl;
    animal *b1 = new animal; // dynamically created

    delete b1;

    // 2. Parametrized constructor

    animal c1(100, 200);
    cout << c1.get_space() << " " << c1.health << endl;

    // 3. DefaUlt Copy constructor
    //  Copying values of another object without creating copy-constructor

    animal k1;
    k1.health = 78;
    k1.pow = 87;
    k1.set_jump(36);
    k1.set_space(63);

    animal h1(k1); // or h1=k1 ;

    cout << h1.health << " " << h1.pow << endl;
    cout << h1.get_jump() << " " << h1.get_space() << endl;
}

// hello main
// Hello constructor
// 10 90
// hello main
// Hello constructor
// I'm cout of the scope now
// Hello parametrized constructor
// 100 200
// Hello constructor
// 78 87
// 36 63
// I'm cout of the scope now
// I'm cout of the scope now
// I'm cout of the scope now
// I'm cout of the scope now