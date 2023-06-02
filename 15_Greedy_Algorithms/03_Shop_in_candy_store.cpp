// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies + N);

        int min_amount = 0;
        int buy = 0;
        int free = N - 1;

        while (buy <= free)
        {
            min_amount = min_amount + candies[buy];
            buy++;
            free = free - K;
        }

        int max_amount = 0;
        buy = N - 1;
        free = 0;

        while (free <= buy)
        {
            max_amount = max_amount + candies[buy];
            buy--;
            free = free + K;
        }

        vector<int> ans;
        ans.push_back(min_amount);
        ans.push_back(max_amount);

        return ans;
    }
};