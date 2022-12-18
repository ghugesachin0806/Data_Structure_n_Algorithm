// Linear_search using recursion
#include <bits/stdc++.h>
using namespace std;

void linear_search(vector<int> pre, int m, int k)
{
    // Base condition
    if (m == pre.size())
    {
        cout << "Key not found" << endl;
        return;
    }
    if (pre[m] == k)
    {
        cout << "Key foud at position " << m + 1 << endl;
        return;
    }
    // processing part
    m++;

    // Recursive relation
    linear_search(pre, m, k);
}

int main()
{
    int t;
    cin >> t;
    vector<int> vect;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m;
        vect.push_back(m);
    }
    int key;
    cin >> key;
    linear_search(vect, 0, key);
}

// -> 6
// -> 56 89 23 41 74 235
// -> 74
// Key foud at position 5