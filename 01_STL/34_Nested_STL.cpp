// Here student have fist name and last name along with different no of subjects , store each subject marks along with first ang last name
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<pair<string, string>, vector<int>> vect;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        string ft, lt;
        cin >> ft >> lt >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            vect[{ft, lt}].push_back(x); // here it is vector here -> vect[{ft,ln}]
        }
    }
    cout << endl;

    cout << "One way of printing : " << endl; // One way of printing elements of map
    for (auto pt : vect)                      // Here pairs will be printed in sorted order
    {
        cout << (pt.first).first << " " << (pt.first).second << " " << (pt.second).size() << endl;
        for (auto ty : pt.second)
        {
            cout << ty << " ";
        }
        cout << endl;
    }
    cout << endl;
    // In below loop all the elements are accessed directly without making any copies

    cout << "Another way of printing : " << endl; // Another way of printing maps
    for (auto &pr : vect)                         // Here '&' sign avoids making cpoies of map elements
    {
        auto &name = pr.first; // Here '&' sign avoids making cpoies of map elements
        // const pair<string,string> &name=pr.first;
        auto &veca = pr.second; // Here '&' sign avoids making cpoies of map elements
        // vector<int> &veca = pr.second;
        cout << name.first << " " << name.second << " " << veca.size() << endl;
        for (auto &tr : veca)
        {
            cout << tr << " ";
        }
        cout << endl;
    }
    cout << endl;
}


// -> 3
// -> z c 4
// -> 44 66 22 11
// -> l m 5
// -> 88 99 55 11 22
// -> a x 6
// -> 22 33 11 88 99 77

// One way of printing :
// a x 6
// 22 33 11 88 99 77
// l m 5
// 88 99 55 11 22
// z c 4
// 44 66 22 11

// Another way of printing :
// a x 6
// 22 33 11 88 99 77
// l m 5
// 88 99 55 11 22
// z c 4
// 44 66 22 11