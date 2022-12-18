#include <bits/stdc++.h>
using namespace std;
// code's easiness can be increased with help of auto_keyword and ranged based loops
int main()
{
    auto a = 1; // Here 'auto' keyword automatically detect the datatype of variable according to its value assigned
    cout << a << endl;

    auto str = "sachin";
    cout << str << endl;

    auto flt = 1.2;
    cout << flt << endl;

    /////////////////////////////////////////////////////////////////////////////////////////

    vector<int> vect = {2, 3, 5, 96, 8, 6, 78};

    // vector<int> :: iterator it = vect.begin();

    for (auto it = vect.begin(); it != vect.end(); it++) // here due to 'auto' keyword, we don't need to write syntax for iterator
    {                                                    // here 'auto' keyword automatically define its datatype
        cout << (*it) << " ";
    }

    cout << endl;
    //////////////////////////////////////////////////////////////////////////////////////
    vector<pair<int, int>> vect2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    // vector<pair<int, int>>::iterator it;

    for (auto it = vect2.begin(); it != vect2.end(); it++) // here due to 'auto' keyword, we don't need to write syntax for iterator
    {                                                      // here 'auto' keyword automatically define its datatype and take care of iterator
        cout << it->first << " " << it->second << endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////
    vector<pair<int, int>> vect3 = {{11, 2}, {12, 3}, {13, 4}, {14, 5}};

    for (auto val : vect3) // for(pair<int,int> val : vect3)
    {
        cout << val.first << " " << val.second << endl;
    }
}

// 1
// sachin
// 1.2
// 2 3 5 96 8 6 78
// 1 2
// 3 4
// 5 6
// 7 8
// 11 2
// 12 3
// 13 4
// 14 5