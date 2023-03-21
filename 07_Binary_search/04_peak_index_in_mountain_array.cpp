// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1])
                start = mid + 1;
            else
                end = mid;
        }

        return end;
    }
};