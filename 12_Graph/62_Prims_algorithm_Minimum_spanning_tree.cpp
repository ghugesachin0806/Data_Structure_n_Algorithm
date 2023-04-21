// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633

#include <bits/stdc++.h>
using namespace std;

// 1 based indexing is used here

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list for given edges
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    // min priority queue
    // pair<weight,pair<node,parent>> is given sequence
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qt;

    // visited array
    vector<bool> visited(n, false);

    // Minimum spanning tree edges
    vector<pair<pair<int, int>, int>> MST_pair;

    // sum of the edges
    int sum = 0;

    // pushing starting element in queue in pair<weight,pair<node,parent>> this form
    qt.push(make_pair(0, make_pair(1, -1)));

    while (!qt.empty())
    {
        int wt = qt.top().first;
        int node = qt.top().second.first;
        int parent = qt.top().second.second;
        qt.pop();

        if (!visited[node])
        {
            visited[node] = true;
            sum = sum + wt;

            for (auto it : adj[node])
            {
                int next_node = it.first;
                int dist = it.second;

                if (!visited[next_node])
                {
                    qt.push(make_pair(dist, make_pair(next_node, node)));
                }
            }

            if (parent != -1)
                MST_pair.push_back(make_pair(make_pair(node, parent), wt));
        }
    }

    return MST_pair;
}