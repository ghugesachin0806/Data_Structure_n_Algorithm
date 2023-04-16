// https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topological_sort(vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &st, int node)
    {
        visited[node] = true;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                topological_sort(adj, visited, st, adj[node][i]);
            }
        }

        // push the current node into stack before returning
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        unordered_map<int, bool> visited;
        stack<int> st;
        vector<int> ans;

        // use DFS traversal for all node
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topological_sort(adj, visited, st, i);
        }

        // convert stack into vector which is topologically sorted
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};