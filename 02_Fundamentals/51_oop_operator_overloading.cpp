// Operator Overloading
#include <iostream>
using namespace std;
class complex
{
public:
    int real;
    int com;
    complex(int i = 0, int j = 0)
    {
        real = i;
        com = j;
    }
    complex add(complex c1)
    {
        complex temp;
        temp.real = real + c1.real;
        temp.com = com + c1.com;
        return temp;
    }
    complex operator+(complex c1) // Here copy of object c1 will be created because of pass by value
    {
        complex temp;
        cout << "object passed variables " << c1.real << " " << c1.com << endl;
        temp.real = this->real + c1.real;
        temp.com = this->com + c1.com;
        return temp;
    }
};
int main()
{
    complex m1(2, 30), m2(5, 6);
    complex c3;
    c3 = m1.add(m2);
    cout << c3.real << " +i " << c3.com << endl;

    complex p1(12, 31), p2(5, 16);
    complex p3;
    p3 = p1 + p2;
    cout << p3.real << " +i " << p3.com << endl;

    int x = 90;
    int y = 120;
    int z = x + y;
    cout << "Value of z : " << z << endl;
    return 0;
}

// 7 +i 36
// object passed variables 5 16
// 17 +i 47
// Value of z : 210