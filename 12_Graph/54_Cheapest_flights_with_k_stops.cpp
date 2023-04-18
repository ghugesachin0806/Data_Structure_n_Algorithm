// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Code here

        vector<pair<int, int>> adj_list[n];

        for (int i = 0; i < flights.size(); i++)
        {
            adj_list[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        int cnt = 0;
        vector<int> price(n, INT_MAX);
        queue<pair<int, int>> qt;
        qt.push({src, 0});
        qt.push({-1, -1});
        price[src] = 0;

        while (!qt.empty())
        {
            int node = qt.front().first;
            int node_price = qt.front().second;
            qt.pop();

            if (cnt == K + 1)
                break;

            if (node == -1)
            {
                cnt++;
                if (!qt.empty())
                    qt.push({-1, -1});

                continue;
            }

            for (auto it : adj_list[node])
            {
                if (it.second + node_price < price[it.first])
                {
                    price[it.first] = it.second + node_price;
                    qt.push({it.first, price[it.first]});
                }
            }
        }

        if (price[dst] == INT_MAX)
            return -1;
        else
            return price[dst];
    }
};