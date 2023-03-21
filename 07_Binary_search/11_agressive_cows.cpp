// https://practice.geeksforgeeks.org/problems/aggressive-cows/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> vect, int k, int mid)
    {
        int last = vect[0];
        int cows = 1;

        for (int i = 0; i < vect.size(); i++)
        {
            if (vect[i] - last >= mid)
            {
                cows++;
                if (cows >= k)
                    return true;

                last = vect[i];
            }
        }

        return false;
    }

    int solve(int n, int k, vector<int> &stalls)
    {
        //    Write your code here.
        sort(stalls.begin(), stalls.end());

        int start = 0;
        int end = stalls[stalls.size() - 1] - stalls[0];
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (solve(stalls, k, mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};