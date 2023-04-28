// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        //min_heap initialization
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                if (min_heap.size() < K)
                    min_heap.push(sum);
                else
                {
                    if (sum > min_heap.top())
                    {
                        min_heap.pop();
                        min_heap.push(sum);
                    }
                }
            }
        }

        return min_heap.top();
    }
};
