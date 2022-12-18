#include <bits/stdc++.h>
using namespace std;

void binarysearch(vector<int> tempt, int start, int end, int key)
{
    // Base case
    if (start > end)
    {
        cout << "Not found !" << endl;
        return;
    }

    int mid = start + (end - start) / 2;

    if (key == tempt[mid])
    {
        cout << "key found at location " << mid + 1 << endl;
        return;
    }

    // Recursive call
    if (tempt[mid] < key)
    {
        binarysearch(tempt, mid + 1, end, key);
    }
    if (tempt[mid] > key)
    {
        binarysearch(tempt, start, mid - 1, key);
    }
}
int main()
{
    int t;
    cin >> t;
    vector<int> vect;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m; // Enter element in sorted format
        vect.push_back(m);
    }
    int start1 = 0;
    int end1 = t - 1;
    int key;
    cin >> key;
    binarysearch(vect, start1, end1, key);
}

// -> 6
// -> 11 22 33 44 55 66
// -> 66

// key found at location 6
