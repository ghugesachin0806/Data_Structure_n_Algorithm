// https://practice.geeksforgeeks.org/problems/number-of-provinces/1

#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> size;
    vector<int> parent;
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
    int numProvinces(vector<vector<int>> adj, int V)
    {
        Disjoint *ds = new Disjoint(V);
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (adj[i][j] == 1)
                {
                    if (ds->find_ultimate_parent(i) != ds->find_ultimate_parent(j))
                    {
                        ds->Union_by_Size(i, j);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (i == ds->parent[i])
                cnt++;
        }

        return cnt;
    }
};