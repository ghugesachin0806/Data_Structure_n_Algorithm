#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &vect2, int start, int end)
{
    int mid = (start + end) / 2;
    // The array which we are dividing into 2 sub-arrays should be sorted
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // copy values in 2 aarays
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = vect2[k++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = vect2[k++];
    }
    // merging two array
    int index1 = 0;
    int index2 = 0;
    k = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            vect2[k++] = first[index1++];
        }
        else
        {
            vect2[k++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        vect2[k++] = first[index1++];
    }

    while (index2 < len2)
    {
        vect2[k++] = second[index2++];
    }
}

void merge_sort(vector<int> &vect1, int start, int end)
{
    // Base case
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    // Left part
    merge_sort(vect1, start, mid);
    // Right part
    merge_sort(vect1, mid + 1, end);
    // Merge sort
    merge(vect1, start, end);
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

    merge_sort(vect, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << vect[i] << " ";
    }
}