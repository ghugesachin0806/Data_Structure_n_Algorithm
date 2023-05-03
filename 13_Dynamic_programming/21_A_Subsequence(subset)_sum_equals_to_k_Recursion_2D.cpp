// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

bool solve(int index, int sum, vector<int> &arr)
{
    if (sum == 0)
        return true;

    if (sum < 0 || index < 0)
        return false;

    // Include call
    bool b1 = solve(index - 1, sum - arr[index], arr);

    // Exclude call
    bool b2 = solve(index - 1, sum, arr);

    return (b1 || b2);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    int curr_index = arr.size() - 1;
    int sum = k;

    return solve(curr_index, sum, arr);
}