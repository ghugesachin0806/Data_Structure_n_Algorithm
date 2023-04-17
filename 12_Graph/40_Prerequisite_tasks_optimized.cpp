// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here

        vector<int> indegree(N, 0);
        vector<int> ans;
        vector<int> adj[N];

        for (auto it : prerequisites)
        {
            adj[it.second].push_back(it.first);
            indegree[it.first]++;
        }

        queue<int> qt;

        for (int i = 0; i < N; i++)
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

        if (ans.size() == N)
            return true;
        else
            return false;
    }
};