#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int is 32-bit

    // Right shift
    int num1 = 11;

    bitset<8> b1(num1);

    cout << b1 << endl;
    b1 = b1 >> 3; // Right shift by three
    cout << b1 << endl;

    // Left shift
    int num2 = 11;

    bitset<8> b2(num2);

    cout << b2 << endl;
    b2 = b2 << 3; // Left shift by three
    cout << b2 << endl;

    // Negation

    bitset<8> b3(num1);

    cout << b3 << endl;
    b3 = (~b3); // Negation
    cout << b3 << endl;

    // XOR operation

    int t1 = 22;
    int t2 = 49;

    bitset<8> bt1(t1);
    bitset<8> bt2(t2);

    cout << bt1 << endl;
    cout << bt2 << endl;

    int t3 = t1 ^ t2;

    bitset<8> bt3(t3);

    cout << bt3 << endl;
}

// Right shift
// 00001011
// 00000001

// Left shift
// 00001011
// 01011000

// Negation
// 00001011
// 11110100

// XOR operation
// 00010110
// 00110001
// ----------------
// 00100111