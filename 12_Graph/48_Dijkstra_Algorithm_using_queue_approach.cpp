// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        queue<pair<int, int>> qt;
        qt.push(make_pair(S, 0));
        dist[S] = 0;

        while (!qt.empty())
        {
            int node = qt.front().first;
            int node_dist = qt.front().second;
            qt.pop();

            for (auto it : adj[node])
            {
                int trav_node = it[0];
                int trav_dist = it[1];

                if (node_dist + trav_dist < dist[trav_node])
                {
                    dist[trav_node] = node_dist + trav_dist;
                    qt.push(make_pair(trav_node, dist[trav_node]));
                }
            }
        }

        return dist;
    }
};