// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool DFS(vector<int> adj[], vector<int> &color, int node, int curr_color)
    {
        color[node] = curr_color;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (color[adj[node][i]] == -1)
            {
                bool b1 = DFS(adj, color, adj[node][i], !curr_color);
                if (!b1)
                    return b1;
            }
            else if (color[adj[node][i]] == color[node])
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);
        int curr_color = 0;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                bool b1 = DFS(adj, color, i, !curr_color);
                if (!b1)
                    return b1;
            }
        }
        return true;
    }
};