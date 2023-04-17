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

        for (auto it : prerequisites)
        {
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

            for (auto it : prerequisites)
            {
                if (it.second == temp)
                {
                    indegree[it.first]--;
                    if (indegree[it.first] == 0)
                        qt.push(it.first);
                }
            }
        }

        if (ans.size() == N)
            return true;
        else
            return false;
    }
};