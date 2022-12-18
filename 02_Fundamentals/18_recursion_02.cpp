// Find whether array is sorted or not using recursion ?

#include <bits/stdc++.h>
using namespace std;
bool issorted(vector<int> arr, int m)
{
    // Base condition
    if (m == arr.size())
    {
        return true;
    }
    if (arr[m] > arr[m + 1])
    {
        return false;
    }
    // processing part
    m++;
    // recursive relation

    return issorted(arr, m);
}
int main()
{
    int n;
    cin >> n;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vect.push_back(m);
    }

    cout << issorted(vect, 0) << endl;
}

// -> 6
// -> 6 5 4 7 8 9
// 0

// -> 5
// -> 7 8 9 10 11 12
// 1