// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int solve(int curr, int k, vector<int> &heights)
{
    if (curr <= 0)
        return 0;

    int temp = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (curr - i >= 0)
            temp = min(temp, solve(curr - i, k, heights) + abs(heights[curr] - heights[curr - i]));
    }

    return temp;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> heights;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        heights.push_back(t);
    }

    cout << solve(n - 1, k, heights) << endl;
}