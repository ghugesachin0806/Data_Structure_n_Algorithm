// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool DFS(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &path, int node)
    {
        visited[node] = true;
        path[node] = true;
        bool b1 = true;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                b1 = DFS(adj, visited, path, adj[node][i]);
                if (b1)
                    return true;
            }
            if (path[adj[node][i]])
                return true;
        }
        path[node] = false;

        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        unordered_map<int, bool> visited;
        unordered_map<int, bool> path;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool b1 = DFS(adj, visited, path, i);
                if (b1)
                    return b1;
            }
        }
        return false;
    }
};