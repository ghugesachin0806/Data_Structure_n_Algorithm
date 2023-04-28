// https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1?page=1&sortBy=newest&query=page1sortBynewest
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapify(vector<int> &vect, int index)
    {
        int large = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < vect.size() && vect[left] > vect[large])
            large = left;
        if (right < vect.size() && vect[right] > vect[large])
            large = right;

        if (large != index)
        {
            swap(vect[large], vect[index]);
            heapify(vect, large);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        for (int i = (arr.size()) / 2 - 1; i >= 0; i--)
        {
            heapify(arr, i);
        }
    }
};
