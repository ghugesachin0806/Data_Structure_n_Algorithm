// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
private:
    vector<int> size;
    vector<int> parent;

public:
    // constructor
    // n is no. of nodes in the graph
    Disjoint(int n)
    {
        // below defined vector size can be used for 0 or 1 based indexing
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // finding ultimate parent and doing path compression
    int find_ultimate_parent(int node)
    {
        if (node == parent[node])
            return node;

        // path compression
        int parent_node = find_ultimate_parent(parent[node]);
        parent[node] = parent_node;

        return parent_node;
    }

    void Union_by_Size(int u, int v)
    {
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u] + size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_v] + size[ulp_u];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qt;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int next_node = it[0];
                int wt = it[1];

                qt.push(make_pair(wt, make_pair(node, next_node)));
            }
        }

        Disjoint *ds = new Disjoint(V);

        while (!qt.empty())
        {
            int node = qt.top().second.first;
            int next_node = qt.top().second.second;
            int wt = qt.top().first;
            qt.pop();

            if (ds->find_ultimate_parent(node) != ds->find_ultimate_parent(next_node))
            {
                sum = sum + wt;
                ds->Union_by_Size(node, next_node);
            }
        }

        return sum;
    }
};