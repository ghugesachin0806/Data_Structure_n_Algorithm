/*

vector has an internal allocator which is in charge of allocating/deallocating
memories from heap for the vector element .So no matter how you create a vector,
its element is always allocated on the heap .

 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        vect.push_back(i);
        cout << "SIZE : " << vect.size() << endl;
        cout << "CAPACITY : " << vect.capacity() << endl;
    }
}

// When the size of vector becomes graeter than the capacity of vector , then capacity of the vector automatically gets doubled.

// SIZE : 1
// CAPACITY : 1
// SIZE : 2
// CAPACITY : 2
// SIZE : 3
// CAPACITY : 4
// SIZE : 4
// CAPACITY : 4
// SIZE : 5
// CAPACITY : 8
// SIZE : 6
// CAPACITY : 8
// SIZE : 7
// CAPACITY : 8
// SIZE : 8
// CAPACITY : 8
// SIZE : 9
// CAPACITY : 16
// SIZE : 10
// CAPACITY : 16
