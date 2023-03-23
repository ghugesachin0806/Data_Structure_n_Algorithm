// https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

int call_median(int ele, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if (minheap.size() == maxheap.size())
    {
        if (ele > maxheap.top())
        {
            minheap.push(ele);
            return minheap.top();
        }
        else
        {
            maxheap.push(ele);
            return maxheap.top();
        }
    }
    else if (maxheap.size() > minheap.size())
    {
        if (ele > maxheap.top())
        {
            minheap.push(ele);
            return (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(ele);

            return (maxheap.top() + minheap.top()) / 2;
        }
    }
    else if (maxheap.size() < minheap.size())
    {
        if (ele < minheap.top())
        {
            maxheap.push(ele);
            return (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(ele);
            return (minheap.top() + maxheap.top()) / 2;
        }
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> vect;

    // max heap
    priority_queue<int> max_heap;
    // min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // median
    int median;

    int size = arr.size();

    min_heap.push(max(arr[0], arr[1]));
    max_heap.push(min(arr[0], arr[1]));

    vect.push_back(arr[0]);
    vect.push_back((arr[0] + arr[1]) / 2);

    for (int i = 2; i < arr.size(); i++)
    {
        int temp = call_median(arr[i], max_heap, min_heap);
        vect.push_back(temp);
    }

    return vect;
}
