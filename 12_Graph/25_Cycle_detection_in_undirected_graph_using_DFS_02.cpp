// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool DFS(vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent)
    {
        visited[node] = true;
        bool b1 = false;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (adj[node][i] != parent)
            {
                if (!visited[adj[node][i]])
                {
                    b1 = DFS(adj, visited, adj[node][i], node);
                }
                else
                    return true;
            }
        }
        return b1;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        unordered_map<int, bool> visited;
        bool b1 = false;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                b1 = DFS(adj, visited, i, -1);
                if (b1)
                    return b1;
            }
        }
        return false;
    }
};