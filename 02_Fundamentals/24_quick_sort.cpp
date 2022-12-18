#include <bits/stdc++.h>
using namespace std;

int quick(vector<int> &vect2, int start, int end)
{
    int pivot = vect2[start];

    int cnt = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (vect2[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotindex = start + cnt;

    swap(vect2[pivotindex], vect2[start]);

    int i = start;
    int j = end;

    while (i < pivotindex && j > pivotindex)
    {
        while (vect2[i] <= pivot)
        {
            i++;
        }

        while (vect2[j] > pivot)
        {
            j--;
        }

        if (i < pivotindex && j > pivotindex)
            swap(vect2[i++], vect2[j--]);
    }

    return pivotindex;
}

void quick_sort(vector<int> &vect1, int start, int end)
{
    // Base case
    if (start >= end)
    {
        return;
    }

    // Processing part
    int p = quick(vect1, start, end);

    // recurcive relation
    quick_sort(vect1, start, p - 1);

    quick_sort(vect1, p + 1, end);
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

    quick_sort(vect, 0, vect.size() - 1);

    for (int i = 0; i < n; i++)
    {
        cout << vect[i] << " ";
    }
}

// -> 8
// -> 98 5 6 78 65 54 68 5
// 5 5 6 54 65 68 78 98