// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);

        int ptr1 = 1;
        int ptr2 = 0;
        int min_platforms = INT_MIN;
        int curr_platforms = 1;

        while (ptr1 < n && ptr2 < n)
        {
            if (arr[ptr1] <= dep[ptr2])
            {
                curr_platforms++;
                ptr1++;
            }
            else
            {
                curr_platforms--;
                ptr2++;
            }

            min_platforms = max(curr_platforms, min_platforms);
        }

        return min_platforms;
    }
};