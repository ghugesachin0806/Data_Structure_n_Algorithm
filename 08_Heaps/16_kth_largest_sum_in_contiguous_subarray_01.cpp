// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        vector<int> vect;
        for (int i = 0; i < N; i++)
        {
            int sum = Arr[i];
            vect.push_back(sum);
            for (int j = i + 1; j < N; j++)
            {
                sum += Arr[j];
                vect.push_back(sum);
            }
        }

        sort(vect.begin(), vect.end());

        return vect[vect.size() - K];
    }
};
