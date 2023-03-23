// https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &vect, int index)
{
    int small = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < vect.size() && vect[left] < vect[small])
        small = left;
    if (right < vect.size() && vect[right] < vect[small])
        small = right;

    if (small != index)
    {
        swap(vect[small], vect[index]);
        heapify(vect, small);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int size = arr.size();
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(arr, i);

    return arr;
}