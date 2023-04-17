// https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {

        // firstly store indegree of each node
        vector<int> ans;
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;
        }

        // then push the 0th indegree nodes in queue

        queue<int> qt;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                qt.push(i);
        }

        // Do BFS
        while (!qt.empty())
        {
            int temp = qt.front();
            ans.push_back(temp);
            qt.pop();

            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;

                if (indegree[adj[temp][i]] == 0)
                    qt.push(adj[temp][i]);
            }
        }

        return ans;
    }
};