// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void solve(int index, int sum, int &cnt, int arr[], int n, int &target)
    {
        if (sum > target || index >= n)
        {
            if (sum == target)
                cnt++;
            return;
        }

        // Exclude call
        solve(index + 1, sum, cnt, arr, n, target);

        // Include call
        sum = sum + arr[index];
        solve(index + 1, sum, cnt, arr, n, target);
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        int cnt = 0;
        int temp_sum = 0;
        int index = 0;

        solve(index, temp_sum, cnt, arr, n, sum);

        return cnt;
    }
};