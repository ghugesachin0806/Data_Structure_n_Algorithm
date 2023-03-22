// https://practice.geeksforgeeks.org/problems/heap-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        int large = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[large])
            large = left;
        if (right < n && arr[right] > arr[large])
            large = right;

        if (large != i)
        {
            swap(arr[large], arr[i]);
            heapify(arr, n, large);
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here

        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // code here
        buildHeap(arr, n);
        int size = n;
        while (size > 1)
        {
            swap(arr[0], arr[size - 1]);
            heapify(arr, size - 1, 0);
            size--;
        }
    }
};

// Time complexity ---> O(NlogN)