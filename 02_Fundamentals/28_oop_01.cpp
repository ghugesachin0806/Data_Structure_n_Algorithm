#include <bits/stdc++.h>
using namespace std;

class animal
{
    // Empty class
};

class bird
{

    int height;
};

int main()
{
    animal a1;
    bird b1;

    cout << "size of animal class " << sizeof(a1) << endl;
    cout << "size of bird class " << sizeof(b1) << endl;
}

// size of animal class 1
// size of bird class 4