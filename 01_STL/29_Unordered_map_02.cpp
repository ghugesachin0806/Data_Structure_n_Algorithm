/*
Given N string and Q queries.
In each query given a string find its frequency
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> zt; // Here unordered map is used instead of map, because of its time complexity -O(1)
    cout << "Enter the total strings - " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        zt[str] = zt[str] + 1;
    }

    cout << "Enter the total queries - " << endl;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        string ptr;
        cin >> ptr;
        cout << zt[ptr] << endl;
    }

    return 0;
}

// Enter the total strings -
// -> 16
// -> sachin
// -> rohan
// -> mohan
// -> sogan
// -> soham
// -> sogan
// -> sachin
// -> rohan
// -> mohan
// -> sachin
// -> sachin
// -> dheeraj
// -> sachin
// -> mohan
// -> sogan
// -> sohan
// Enter the total queries -
// -> 2
// -> sachin
// 5
// -> mohan
// 3