// https://practice.geeksforgeeks.org/problems/course-schedule/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        // code here
        vector<int> ans;
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for (int i = 0; i < m; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> qt;

        for (int i = 0; i < n; i++)
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

        if (ans.size() == n)
            return ans;
        else
        {
            vector<int> curr;
            return curr;
        }
    }
};