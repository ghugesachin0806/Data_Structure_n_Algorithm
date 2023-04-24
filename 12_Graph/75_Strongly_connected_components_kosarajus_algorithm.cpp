// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS_Toposort(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, int node)
    {
        visited[node] = true;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                DFS_Toposort(adj, visited, st, it);
            }
        }

        st.push(node);
    }
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // Topological sorting graph nodes
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS_Toposort(adj, visited, st, i);
            }
        }

        // Reverse the edges of graph
        vector<vector<int>> reverse_adj(V, vector<int>());

        int k = 0;
        for (auto it : adj)
        {
            for (auto u : it)
            {
                reverse_adj[u].push_back(k);
            }
            k++;
        }

        // Call the DFS till stack gets empty
        stack<int> dummy_st;
        vector<bool> visited2(V, false);
        int cnt = 0; // count the number of strongly connected graphs

        while (!st.empty())
        {
            int temp = st.top();
            st.pop();

            if (!visited2[temp])
            {
                DFS_Toposort(reverse_adj, visited2, dummy_st, temp);
                cnt++;
            }
        }

        return cnt;
    }
};