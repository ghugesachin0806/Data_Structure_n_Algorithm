// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj_list[n + 1];

        for (int i = 0; i < edges.size(); i++)
        {
            adj_list[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj_list[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qt;

        qt.push(make_pair(0, 1));
        dist[1] = 0;
        parent[1] = -1;

        while (!qt.empty())
        {
            int node = qt.top().second;
            int node_dist = qt.top().first;
            qt.pop();

            for (auto it : adj_list[node])
            {
                if (node_dist + it.second < dist[it.first])
                {
                    dist[it.first] = node_dist + it.second;
                    qt.push({dist[it.first], it.first});
                    parent[it.first] = node;
                }
            }
        }

        vector<int> ans;

        if (parent[n] == -1)
        {
            ans.push_back(-1);
            return ans;
        }
        else
        {
            ans.push_back(n);
            int curr_node = n;
            while (parent[curr_node] != -1)
            {
                curr_node = parent[curr_node];
                ans.push_back(curr_node);
            }

            reverse(ans.begin(),ans.end());

            return ans;
        }
    }
};