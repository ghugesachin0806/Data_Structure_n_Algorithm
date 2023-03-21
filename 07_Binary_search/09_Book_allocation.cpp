// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum number of pages.
    bool solve(int vect[], int n, int m, int start, int end, int mid)
    {
        int bookPage = 0;
        int student = 1;

        for (int i = 0; i < n; i++)
        {
            if (bookPage + vect[i] <= mid)
            {
                bookPage += vect[i];
            }
            else
            {
                student++;

                if (vect[i] > mid)
                    return false;

                bookPage = 0;
                i--;
            }
        }

        if (student > m)
            return false;

        else
            return true;
    }

    int findPages(int A[], int N, int M)
    {
        if (N < M)
            return -1;

        int start = 0;
        int end = 0;
        for (int i = 0; i < N; i++)
            end += A[i];

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (solve(A, N, M, start, end, mid))
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