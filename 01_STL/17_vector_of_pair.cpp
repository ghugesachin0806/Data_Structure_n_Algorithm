#include <bits/stdc++.h>
using namespace std;

void print_me(vector<pair<int, int>> m)
{
    cout << "Size - " << m.size() << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i].first << " " << m[i].second << endl;
    }
}

int main()
{
    vector<pair<int, int>> vect = {{1, 2}, {3, 4}, {5, 6}, {7, 8}}; // values taken by vector of pairs
    print_me(vect);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<pair<int, int>> v; // Here vector of pairs declared
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) // input taken by user for vector of pairs
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y}); // v.push_back(make_pair(x,y)) , also can be used here
    }
    print_me(v);
    return 0;
}

// Size - 4
// 1 2
// 3 4
// 5 6
// 7 8
// 5
// 1 2 3 4 5 6 7 8 9 10
// Size - 5
// 1 2
// 3 4
// 5 6
// 7 8
// 9 10