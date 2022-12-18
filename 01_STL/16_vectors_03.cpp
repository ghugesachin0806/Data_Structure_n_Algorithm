// This code is necessary to understand for the inputs given  in sequence where size no. of elements in sequence is unknown 

#include <bits/stdc++.h>
using namespace std;

int main()
{ 

    vector<int> v;
    while (1)
    {
        int n;
        cin >> n;
        if (n > 0)             // Here we can break the input loop values like shown in the code
            v.push_back(n);
        else
            break;
    }
    int mx = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < 100)
        {
            mx = max(mx, v[i]);
        }
    }
    cout << mx << endl;
    return 0;
}