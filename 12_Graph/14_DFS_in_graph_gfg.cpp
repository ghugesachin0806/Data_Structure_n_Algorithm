// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {
        ans.push_back(node);
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
                DFS(adj, visited, ans, i);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        unordered_map<int, bool> visited;

        DFS(adj, visited, ans, 0);

        return ans;
    }
};