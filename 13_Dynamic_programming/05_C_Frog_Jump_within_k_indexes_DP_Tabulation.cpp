// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int solve(int curr, int n, int k, vector<int> &heights, vector<int> &DP)
{
    DP[0] = 0;
    if (curr == 0)
        return 0;

    for (int i = 1; i < n; i++)
    {
        int temp = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                temp = min(temp, DP[i - j] + abs(heights[i - j] - heights[i]));
        }
        DP[i] = temp;
    }

    return DP[n - 1];
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

    cout << solve(n - 1, n, k, heights, DP) << endl;
}