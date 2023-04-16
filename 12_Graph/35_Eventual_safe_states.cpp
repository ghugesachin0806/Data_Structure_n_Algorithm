// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool DFS(vector<int> adj[], vector<int> &path, vector<int> &safe, vector<int> &visited, int node)
    {
        visited[node] = 1;
        path[node] = 1;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (safe[adj[node][i]] == 1)
                continue;
            else if (safe[adj[node][i]] == -1 || path[adj[node][i]] == 1)
            {
                safe[node] = -1;
                return false;
            }
            else if (!visited[adj[node][i]])
            {
                bool b1 = DFS(adj, path, safe, visited, adj[node][i]);
                if (!b1)
                {
                    safe[node] = -1;
                    return false;
                }
            }
        }
        path[node] = 0;
        safe[node] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> safe(V, 0);
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (safe[i] == 0 && visited[i] == 0)
            {
                vector<int> path(V, 0);
                DFS(adj, path, safe, visited, i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (safe[i] == 1)
                ans.push_back(i);
        }

        return ans;
    }
};