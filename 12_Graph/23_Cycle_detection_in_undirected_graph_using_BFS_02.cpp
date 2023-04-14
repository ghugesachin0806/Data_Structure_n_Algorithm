// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// In below code parent node is stored with current node

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool BSF(vector<int> adj[], unordered_map<int, bool> &visited, int node)
    {
        visited[node] = true;
        queue<pair<int, int>> qt;
        qt.push(make_pair(node, -1));

        while (!qt.empty())
        {
            int temp_node = qt.front().first;
            int temp_parent = qt.front().second;
            qt.pop();

            for (int i = 0; i < adj[temp_node].size(); i++)
            {
                if (adj[temp_node][i] != temp_parent)
                {
                    if (!visited[adj[temp_node][i]])
                    {
                        qt.push(make_pair(adj[temp_node][i], temp_node));
                        visited[adj[temp_node][i]] = true;
                    }
                    else
                        return true;
                }
            }
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
                bool b1 = BSF(adj, visited, i);
                if (b1)
                    return true;
            }
        }
        return false;
    }
};