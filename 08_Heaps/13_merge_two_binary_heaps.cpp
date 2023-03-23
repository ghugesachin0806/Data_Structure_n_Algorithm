// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

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
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // your code here
        vector<int> vect;

        for (auto i : a)
        {
            vect.push_back(i);
        }
        for (auto i : b)
        {
            vect.push_back(i);
        }

        for (int i = vect.size() / 2 - 1; i >= 0; i--)
        {
            heapify(vect, i);
        }

        return vect;
    }
};