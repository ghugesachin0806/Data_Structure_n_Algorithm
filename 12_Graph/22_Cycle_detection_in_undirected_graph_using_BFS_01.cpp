// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// In below code while traversing the code , if that node have 2 nodes connected which is already visited,
// then cycle is present there

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool BSF(vector<int> adj[], unordered_map<int, bool> &visited, int node)
    {
        queue<int> qt;
        qt.push(node);
        visited[node] = 1;

        while (!qt.empty())
        {
            int cnt = 0;
            int temp = qt.front();
            qt.pop();

            for (int i = 0; i < adj[temp].size(); i++)
            {
                if (visited[adj[temp][i]])
                    cnt++;
                else
                {
                    qt.push(adj[temp][i]);
                    visited[adj[temp][i]] = 1;
                }
            }
            if (cnt == 2)
                return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool b1 = BSF(adj, visited, i);
                if (b1)
                    return b1;
            }
        }
        return false;
    }
};