// https://leetcode.com/problems/critical-connections-in-a-network/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<int> adj_list[], int &timer, int parent, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<vector<int>> &bridge_edges, int node)
    {
        visited[node] = true;
        disc[node] = timer;
        low[node] = timer;
        timer++;

        for (auto it : adj_list[node])
        {
            // parent node
            if (it == parent)
                continue;
            // Not visited
            else if (!visited[it])
            {
                DFS(adj_list, timer, node, visited, disc, low, bridge_edges, it);

                // Update low
                low[node] = min(low[node], low[it]);

                // check if bridge edge is present or not
                if (low[it] > disc[node])
                {
                    bridge_edges.push_back({it, node});
                }
            }
            // Visited
            else
            {
                // update low from already visited node
                low[node] = min(low[node], disc[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // Adjacency list
        vector<int> adj_list[n];

        for (int i = 0; i < connections.size(); i++)
        {
            adj_list[connections[i][0]].push_back(connections[i][1]);
            adj_list[connections[i][1]].push_back(connections[i][0]);
        }

        // timer
        int timer = 0;

        // parent
        int parent = -1;

        // visited vector
        vector<bool> visited(n, false);

        // discovery vector
        vector<int> disc(n, 0);

        // lowest possible discovery vector
        vector<int> low(n, 0);

        // critical edges vector
        vector<vector<int>> bridge_edges;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(adj_list, timer, parent, visited, disc, low, bridge_edges, i);
            }
        }

        return bridge_edges;
    }
};