#include <bits/stdc++.h>
using namespace std;

// Characters are 8-bits
// In ASCII values of char in small and capital letters are differ at 5th bit from LSB(0-indexing) respectively.

int main()
{
    for (char ch = 'A'; ch < 'F'; ch++)
    {
        int temp = ch;
        bitset<8> b1(temp);
        cout << ch << "->" << b1 << endl;
    }
    cout << endl;
    for (char ch = 'a'; ch < 'f'; ch++)
    {
        int temp = ch;
        bitset<8> b1(temp);
        cout << ch << "->" << b1 << endl;
    }

    // There is difference of 5th bit from LSB(0-indexing) for small and capital letters

    // 00100000 -> ' '(blank_space)
    // 01011111 -> '_'(underscore)

    // Uppercase to Lowercase conversion
    for (char ch = 'A'; ch < 'F'; ch++)
    {
        char temp = (ch | ' ');
        cout << ch << "->" << temp << endl;
    }

    // Lowercase to uppercase conversion
    for (char ch = 'a'; ch < 'f'; ch++)
    {
        char temp = (ch & '_');
        cout << ch << "->" << temp << endl;
    }
}

// A->01000001
// B->01000010
// C->01000011
// D->01000100
// E->01000101

// a->01100001
// b->01100010
// c->01100011
// d->01100100
// e->01100101

// A->a
// B->b
// C->c
// D->d
// E->e

// a->A
// b->B
// c->C
// d->D
// e->E