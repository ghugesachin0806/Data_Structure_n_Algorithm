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

        int stop = 0;
        vector<int> price(n, INT_MAX);
        queue<pair<int, pair<int, int>>> qt;

        qt.push(make_pair(stop, make_pair(src, 0)));
        price[src] = 0;

        while (!qt.empty())
        {

            int temp_stop = qt.front().first;
            int node = qt.front().second.first;
            int node_price = qt.front().second.second;
            qt.pop();

            if (temp_stop == K + 1)
                break;

            for (auto it : adj_list[node])
            {
                if (price[it.first] > node_price + it.second)
                {
                    price[it.first] = node_price + it.second;

                    qt.push(make_pair(temp_stop + 1, make_pair(it.first, price[it.first])));
                }
            }
        }

        if (price[dst] == INT_MAX)
            return -1;
        else
            return price[dst];
    }
};