// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

// 1 based indexing

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // Write your code here
    vector<int> adj[n + 1];

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    // Do BFS traversal
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> qt;
    qt.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!qt.empty())
    {
        int temp = qt.front();
        qt.pop();

        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (!visited[adj[temp][i]])
            {
                qt.push(adj[temp][i]);
                visited[adj[temp][i]] = true;
                parent[adj[temp][i]] = temp;
            }
        }
    }

    vector<int> ans;

    if (!visited[t])
        return ans;
    else
    {
        int curr_node = t;
        ans.push_back(t);

        while (curr_node != s)
        {
            curr_node = parent[curr_node];
            ans.push_back(curr_node);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
}
