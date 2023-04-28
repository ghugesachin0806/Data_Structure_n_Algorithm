// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int solve(int curr, int k, vector<int> &heights, vector<int> &DP)
{
    if (curr <= 0)
        return 0;

    if (DP[curr] != -1)
        return DP[curr];

    int temp = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (curr - i >= 0)
            temp = min(temp, solve(curr - i, k, heights, DP) + abs(heights[curr] - heights[curr - i]));
    }

    DP[curr] = temp;

    return DP[curr];
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> heights;
    vector<int> DP(n, -1);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        heights.push_back(t);
    }

    cout << solve(n - 1, k, heights, DP) << endl;
}