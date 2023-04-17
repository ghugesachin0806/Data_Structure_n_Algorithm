// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];
        vector<int> dist(N, -1);
        unordered_map<int, bool> visited;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int cnt = 1;
        queue<int> qt;
        qt.push(src);
        qt.push(-1);
        dist[src] = 0;
        visited[src] = true;

        while (!qt.empty())
        {
            int temp = qt.front();
            qt.pop();

            if (temp == -1)
            {
                cnt++;
                if (!qt.empty())
                    qt.push(-1);
                continue;
            }

            for (auto it : adj[temp])
            {
                if (!visited[it])
                {
                    qt.push(it);
                    visited[it] = true;
                    dist[it] = cnt;
                }
            }
        }

        return dist;
    }
};