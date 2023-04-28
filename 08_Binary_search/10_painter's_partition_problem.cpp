// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int arr[], int n, int k, long long int start, long long int end, long long int mid)
    {
        long long int boards = 0;
        long long int painters = 1;

        for (int i = 0; i < n; i++)
        {
            if (boards + arr[i] <= mid)
            {
                boards += arr[i];
            }
            else
            {
                painters++;
                if (arr[i] > mid || painters > k)
                    return false;

                boards = 0;
                i--;
            }
        }

        return true;
    }

    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long int start = 0;
        long long int end = 0;
        for (int i = 0; i < n; i++)
            end += arr[i];

        while (start < end)
        {
            long long int mid = start + (end - start) / 2;

            if (solve(arr, n, k, start, end, mid))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return end;
    }
};