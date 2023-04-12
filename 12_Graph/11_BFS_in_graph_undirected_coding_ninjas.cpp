// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

#include <bits/stdc++.h>
using namespace std;

void edgesToList(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adj_list)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
}

void BSF(unordered_map<int, set<int>> &adj_list, unordered_map<int, bool> &visited, int node, vector<int> &ans)
{
    queue<int> qt;
    qt.push(node);
    visited[node] = true;

    while (!qt.empty())
    {
        int temp = qt.front();
        qt.pop();

        // store the front node
        ans.push_back(temp);

        // push eligible nodes to queue
        for (auto i : adj_list[temp])
        {
            if (!visited[i])
            {
                visited[i] = true;
                qt.push(i);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adj_list; // set gives answer in sorted format
    vector<int> ans;

    edgesToList(edges, adj_list);

    // Traverse all the components of graph ,it will include if any disconnected components are there in graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            BSF(adj_list, visited, i, ans);
        }
    }

    return ans;
}