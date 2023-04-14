// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool DFS(vector<int> adj[], unordered_map<int, bool> &visited, int node)
    {
        visited[node] = true;
        int cnt = 0;
        bool b1 = false;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (visited[adj[node][i]])
                cnt++;
            else
            {
                bool b1 = DFS(adj, visited, adj[node][i]);
                if (b1)
                    return b1;
            }

            if (cnt == 2)
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool b1 = DFS(adj, visited, i);
                if (b1)
                    return b1;
            }
        }
        return false;
    }
};