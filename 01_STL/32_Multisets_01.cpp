#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> vect; // In this type duplicate/repitated values are allowed , all values are in sorted/ordered manner while accessing the values
    vect.insert(34);    // This time complexity of insertion and access/printing is O(log n)
    vect.insert(78);
    vect.insert(56);
    vect.insert(13);
    vect.insert(90);
    vect.insert(34); // Here duplicate values are allowed for multiset

    for (auto pt : vect) // It will return set in ordered/sorted manner
    {
        cout << pt << endl;
    }

    auto it = vect.find(34); // here, iterator 'it' will point to the first element, if repitated/duplicates values are present

    cout << (*it) << endl;
    cout << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    multiset<string> vect2;
    int n;
    cout << "Enter the no. of strings to be inserted - ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vect2.insert(str);
    }
    cout << endl;
    // One way of using for loop
    for (auto it = vect2.begin(); it != vect2.end(); it++)
    {
        cout << (*it) << endl;
    }
    cout << endl;
    // Another way of using for loop
    for (auto lp : vect2)
    {
        cout << lp << endl;
    }
    cout<<endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto pk = vect2.find("sachin");
    if (pk == vect2.end())
    {
        cout << "Value is not present" << endl;
    }
    else
    {
        cout << "Value is present" << endl;
    }
    cout<<endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vect2.erase("soham"); // all the soham values will be earased

    auto pl = vect2.begin();
    vect2.erase(pl); // Only iterator pointing value get deleted or removed

    for (auto ve : vect2)
    {
        cout << ve << endl;
    }
}
// 13
// 34
// 34
// 56
// 78
// 90
// 34

// Enter the no. of strings to be inserted - 8
// -> sachin
// -> soham 
// -> rohan
// -> sachin
// -> soham
// -> sachin
// -> krishna
// -> soham

// krishna
// rohan
// sachin
// sachin
// sachin
// soham
// soham
// soham

// krishna
// rohan
// sachin
// sachin
// sachin
// soham
// soham
// soham

// Value is present

// rohan
// sachin
// sachin
// sachin