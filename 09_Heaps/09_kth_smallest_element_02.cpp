// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> qt;
        for (int i = l; i <= r; i++)
        {
            qt.push(arr[i]);
        }

        int temp;
        while (k > 0)
        {
            temp = qt.top();
            qt.pop();
            k--;
        }

        return temp;
    }
};