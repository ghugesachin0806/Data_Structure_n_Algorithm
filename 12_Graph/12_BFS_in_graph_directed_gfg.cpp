// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BSF(vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {
        queue<int> qt;
        qt.push(node);

        while (!qt.empty())
        {
            int temp = qt.front();
            qt.pop();
            visited[temp] = 1;

            ans.push_back(temp);

            for (auto i : adj[temp])
            {
                if (!visited[i])
                    qt.push(i);

                visited[i] = 1;
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        unordered_map<int, bool> visited;

        BSF(adj, visited, ans, 0);

        return ans;
    }
};