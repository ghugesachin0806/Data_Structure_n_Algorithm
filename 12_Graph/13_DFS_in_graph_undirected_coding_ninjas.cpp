// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void EdgestoList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj_list)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}

void DFS(unordered_map<int, list<int>> &adj_list, vector<int> &temp, unordered_map<int, bool> &visited, int node)
{
    temp.push_back(node);
    visited[node] = true;

    for (auto i : adj_list[node])
    {
        if (!visited[i])
            DFS(adj_list, temp, visited, i);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adj_list;
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    EdgestoList(edges, adj_list);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            DFS(adj_list, temp, visited, i);
            ans.push_back(temp);
        }
    }
    return ans;
}