// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        vector<pair<long long, long long>> adj_list[n];

        for (long long i = 0; i < roads.size(); i++)
        {
            adj_list[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
            adj_list[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
        }

        vector<long long> shortcut(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> qt;

        long long mod = (1e9 + 7);

        qt.push(make_pair(0, 0));
        dist[0] = 0;
        shortcut[0] = 1;

        while (!qt.empty())
        {
            long long node = qt.top().second;
            long long node_dist = qt.top().first;
            qt.pop();

            for (auto it : adj_list[node])
            {
                if (node_dist + it.second < dist[it.first])
                {
                    dist[it.first] = node_dist + it.second;
                    shortcut[it.first] = shortcut[node];

                    qt.push(make_pair(dist[it.first], it.first));
                }
                else if (node_dist + it.second == dist[it.first])
                {
                    shortcut[it.first] = (shortcut[node] + shortcut[it.first]) % mod;
                }
            }
        }

        return shortcut[n - 1] % mod;
    }
};