// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;

        for (long long i = 0; i < n; i++)
        {
            min_heap.push(arr[i]);
        }

        long long sum = 0;

        while (min_heap.size() > 1)
        {
            long long  temp1 = min_heap.top();
            min_heap.pop();
            long long temp2 = min_heap.top();
            min_heap.pop();
            sum = sum + temp1 + temp2;

            min_heap.push(temp1 + temp2);
        }

        return sum;
    }
};