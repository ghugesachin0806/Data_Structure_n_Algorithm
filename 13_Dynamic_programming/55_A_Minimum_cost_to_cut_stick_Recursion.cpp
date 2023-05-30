// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int ptr1, int ptr2, vector<int> &cuts)
    {
        if (ptr1 > ptr2)
            return 0;

        int mini = INT_MAX;

        for (int i = ptr1; i <= ptr2; i++)
        {
            int temp = solve(ptr1, i - 1, cuts) + solve(i + 1, ptr2, cuts) + (cuts[ptr2 + 1] - cuts[ptr1 - 1]);
            mini = min(mini, temp);
        }
        return mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        int ptr1 = 1;
        int ptr2 = cuts.size() - 2;

        sort(cuts.begin(), cuts.end());

        return solve(ptr1, ptr2, cuts);
    }
};