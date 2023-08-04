// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum number of pages.
    bool soln(int mid, int M, int N, int A[])
    {
        int temp = 0;
        int cnt = 1;
        for (int i = 0; i < N; i++)
        {
            if (temp + A[i] <= mid)
            {
                temp += A[i];
            }
            else
            {
                cnt++;
                if (cnt > M || A[i] > mid)
                    return false;

                temp = A[i];
            }
        }

        return true;
    }
    int findPages(int A[], int N, int M)
    {
        // code here
        if (M > N)
            return -1;

        int sum = 0;

        for (int i = 0; i < N; i++)
        {
            sum += A[i];
        }

        int start = 0;
        int end = sum;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (soln(mid, M, N, A))
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};