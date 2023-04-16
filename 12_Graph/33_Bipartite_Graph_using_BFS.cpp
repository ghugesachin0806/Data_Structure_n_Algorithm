// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool BSF(vector<int> adj[], vector<int> &color, int node)
    {
        queue<int> qt;
        qt.push(node);
        color[node] = 0;

        while (!qt.empty())
        {
            int temp = qt.front();
            qt.pop();

            for (auto it : adj[temp])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[temp];
                    qt.push(it);
                }
                else if (color[it] == color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                bool b1;
                b1 = BSF(adj, color, i);
                if (!b1)
                    return b1;
            }
        }
        return true;
    }
};