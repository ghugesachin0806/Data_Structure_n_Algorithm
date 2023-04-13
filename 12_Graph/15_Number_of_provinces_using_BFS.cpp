// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFS(vector<vector<int>> &isConnected, unordered_map<int, bool> &visited, int node)
    {
        queue<int> qt;
        qt.push(node);
        visited[node] = 1;

        while (!qt.empty())
        {
            for (int i = 0; i < isConnected.size(); i++)
            {
                if (isConnected[qt.front()][i])
                {
                    if (!visited[i])
                    {
                        qt.push(i);
                        visited[i] = 1;
                    }
                }
            }
            qt.pop();
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int cnt = 0;
        unordered_map<int, bool> visited;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                BFS(isConnected, visited, i);
                cnt++;
            }
        }

        return cnt;
    }
};