// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        queue<int> qt;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                qt.push(i);
        }

        while (!qt.empty())
        {
            int temp = qt.front();
            qt.pop();
            ans.push_back(temp);

            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;

                if (indegree[adj[temp][i]] == 0)
                    qt.push(adj[temp][i]);
            }
        }

        if (ans.size() == V)
            return false;
        else
            return true;
    }
};