#include <bits/stdc++.h>
using namespace std;

class parent
{
protected:
    int c;
    int d;

public:
    int x;
    int y;
    parent()
    {
        c = 15;
        d = 25;
    }
    void parent_write_me(int i, int j)
    {
        this->x = i;
        this->y = j;
    }
    void parent_read_me()
    {
        cout << "Value of x: " << x << " y: " << y << endl;
    }
    void parent_pro_value(int j, int k)
    {
        this->c = j;
        this->d = k;
    }
};

class child1 : public parent
{
public:
    int m;
    int n;

    void set_child(int i, int j)
    {
        this->m = i;
        this->n = j;
    }
    void set_pro_value(int j, int k)
    {
        this->c = j;
        this->d = k;
    }
    void get_child()
    {
        cout << "Value of x : " << x << " y : " << y << endl;
        cout << "Value of m : " << m << " n : " << n << endl;
        cout << "Value of c : " << c << " d : " << d << endl;
    }
};

int main()
{
    child1 cat;

    // calling parent member functions by child class object
    cat.parent_write_me(10, 20);
    cat.parent_read_me();

    cat.set_child(100, 200);
    cat.get_child();

    // Accessing parent class data members by child class object
    cat.x = 90;
    cat.y = 60;
    cat.parent_read_me();

    // Accessing protected data members by child class object
    cat.set_pro_value(2, 3);
    cat.get_child();
}

// Value of x: 10 y: 20

// Value of x : 10 y : 20
// Value of m : 100 n : 200
// Value of c : 15 d : 25

// Value of x: 90 y: 60

// Value of x : 90 y : 60
// Value of m : 100 n : 200
// Value of c : 2 d : 3