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
        // adjacency list is stored in the form of node and its weight in vector form above
        // vector<vector<int>> adj[]

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qt;

        qt.push(make_pair(0, S));
        dist[S] = 0;

        while (!qt.empty())
        {
            int node = qt.top().second;
            int dist_node = qt.top().first;
            qt.pop();

            for (auto it : adj[node])
            {
                int trav_node = it[0];
                int trav_dist = it[1];

                if (dist_node + trav_dist < dist[trav_node])
                {
                    dist[trav_node] = dist_node + trav_dist;
                    qt.push(make_pair(dist[trav_node], trav_node));
                }
            }
        }

        return dist;
    }
};

// time complexity -> E log(V)
// E -> No. of Edges
// V -> No. of vertices