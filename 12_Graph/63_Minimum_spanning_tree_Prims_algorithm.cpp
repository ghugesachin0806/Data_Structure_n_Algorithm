// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qt;

        vector<bool> visited(V, false);

        qt.push(make_pair(0, 0));

        while (!qt.empty())
        {
            int node = qt.top().second;
            int wt = qt.top().first;
            qt.pop();

            if (!visited[node])
            {
                visited[node] = true;
                sum = sum + wt;

                for (auto it : adj[node])
                {
                    int next_node = it[0];
                    int next_wt = it[1];

                    if (!visited[next_node])
                    {
                        qt.push(make_pair(next_wt, next_node));
                    }
                }
            }
        }

        return sum;
    }
};