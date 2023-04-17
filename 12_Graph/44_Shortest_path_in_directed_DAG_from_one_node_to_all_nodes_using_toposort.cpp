// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void DSF(vector<pair<int, int>> adj[], stack<int> &st, unordered_map<int, bool> &visited, int node)
    {
        visited[node] = true;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i].first])
            {
                DSF(adj, st, visited, adj[node][i].first);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here

        // compute the toposort
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }

        stack<int> st;
        vector<int> toposort;
        unordered_map<int, bool> visited;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                DSF(adj, st, visited, i);
            }
        }

        // distance vector with INT_MAX value
        vector<int> dist(N, INT_MAX);

        // mark the source node distance as 0
        // Here source node is given as 0
        dist[0] = 0;

        while (!st.empty())
        {
            int temp = st.top();
            st.pop();

            if (dist[temp] != INT_MAX)
            {
                for (auto it : adj[temp])
                {
                    if (dist[temp] + it.second < dist[it.first])
                    {
                        dist[it.first] = it.second + dist[temp];
                    }
                }
            }

            // -1 distance means infinity
            if (dist[temp] == INT_MAX)
                dist[temp] = -1;
        }

        return dist;
    }
};