// https://practice.geeksforgeeks.org/problems/connecting-the-graph/1

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
    int Solve(int n, vector<vector<int>> &edge)
    {
        // code here
        int extra_edges = 0;
        Disjoint *ds1 = new Disjoint(n);

        for (auto it : edge)
        {
            if (ds1->find_ultimate_parent(it[0]) != ds1->find_ultimate_parent(it[1]))
            {
                ds1->Union_by_Size(it[0], it[1]);
            }
            else
            {
                extra_edges++;
            }
        }

        Disjoint *ds2 = new Disjoint(n);

        for (auto it : edge)
        {
            ds2->Union_by_Size(it[0], it[1]);
        }

        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ds2->parent[i])
                provinces++;
        }

        int edges_required = provinces - 1;

        if (extra_edges >= edges_required)
            return edges_required;
        else
            return -1;
    }
};