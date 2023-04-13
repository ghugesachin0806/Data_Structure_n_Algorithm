// https://practice.geeksforgeeks.org/problems/number-of-provinces/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int node)
    {
        visited[node] = 1;

        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[node][i])
            {
                if (!visited[i])
                    DFS(adj, visited, i);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        unordered_map<int, bool> visited;
        int cnt = 0;

        for (int i = 0; i < adj.size(); i++)
        {
            if (!visited[i])
            {
                cnt++;
                DFS(adj, visited, i);
            }
        }

        return cnt;
    }
};