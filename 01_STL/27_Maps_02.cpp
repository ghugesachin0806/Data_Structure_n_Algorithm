// Given N strings , print unique strings in lexiographical order with their frequency
// N<=10e5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> vect;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vect[str] = vect[str] + 1; // Here string input taken in map as well as value for the frequency is taken
        // vect[str]++;
    }

    for (auto pt : vect) // Here strings are printed in lexiographical order
    {
        cout << pt.first << " " << pt.second << endl;
    }
}
// -> 8
// -> sachin
// -> sachin
// -> rohan
// -> mohan
// -> rakesh
// -> rohan
// -> sachin
// -> rohan
// mohan 1
// rakesh 1
// rohan 3
// sachin 3