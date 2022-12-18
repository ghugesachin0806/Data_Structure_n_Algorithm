// https://www.hackerearth.com/practice/algorithms/sorting/advanced-sorting/practice-problems/algorithm/the-monk-and-class-marks/
// The Monk and Class Marks
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, multiset<string>> vect; // Multiset is used because there may be students with same name and mark
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int mark;
        string str;
        cin >> str >> mark;
        vect[mark].insert(str);
    }
    cout << endl;

    auto last_it = vect.end();
    --last_it;
    cout << "Output" << endl;
    // Observe the code carefully
    while (true)
    {
        auto &student = (*last_it).second;
        auto &marks = (*last_it).first;
        for (auto &nm : student)
        {
            cout << nm << " " << marks << endl;
        }
        if (last_it == vect.begin())
            break;
        last_it--;
    }
}
// -> 7
// -> sachin 80
// -> ghuge 90
// -> free 76
// -> sachin 90
// -> sachin 80
// -> free 56
// -> dhiraj 78

// Output
// ghuge 90
// sachin 90
// sachin 80
// sachin 80
// dhiraj 78
// free 76
// free 56