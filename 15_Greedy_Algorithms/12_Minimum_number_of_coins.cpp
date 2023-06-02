// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> money{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

        int ptr = money.size() - 1;
        vector<int> ans;

        while (N > 0)
        {
            if (N >= money[ptr])
            {
                N = N - money[ptr];
                ans.push_back(money[ptr]);
            }
            else
                ptr--;
        }
        return ans;
    }
};