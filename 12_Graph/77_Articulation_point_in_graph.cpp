// https://practice.geeksforgeeks.org/problems/articulation-point-1/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<int> adj_list[], int &timer, int parent, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &arti_point, int node)
    {
        int child = 0;
        visited[node] = true;
        disc[node] = timer;
        low[node] = timer;
        timer++;

        for (auto it : adj_list[node])
        {
            // parent node
            if (it == parent)
                continue;
            // Not visited
            else if (!visited[it])
            {
                DFS(adj_list, timer, node, visited, disc, low, arti_point, it);

                // Update low
                low[node] = min(low[node], low[it]);

                // check the articulte point
                if (low[it] >= disc[node] && parent != -1)
                {
                    arti_point[node] = 1;
                }
                child++;
            }
            // Visited
            else
            {
                // update low from already visited node
                low[node] = min(low[node], disc[it]);
            }
        }
        if (child > 1 && parent == -1)
            arti_point[node] = 1;
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // timer
        int timer = 0;

        // discovery vector
        vector<int> disc(V, 0);

        // lowest possible discovery vector
        vector<int> low(V, 0);

        // visited vector
        vector<bool> visited(V, false);

        // parent
        int parent = -1;

        // Articulation point vector
        vector<int> arti_point(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(adj, timer, parent, visited, disc, low, arti_point, i);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (arti_point[i] == 1)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            return {-1};
        else
            return ans;
    }
};