// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633

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

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    // order edges by ascending weights with u->v
    // pair<wt,pair<u,v>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qt;

    for (auto it : g)
    {
        qt.push(make_pair(it.second, make_pair(it.first.first, it.first.second)));
        qt.push(make_pair(it.second, make_pair(it.first.second, it.first.first))); // Not need to include
    }

    int sum = 0;

    // pair<pair<u,v>,wt>
    vector<pair<pair<int, int>, int>> ans;

    Disjoint *ds = new Disjoint(n);

    while (!qt.empty())
    {
        int u = qt.top().second.first;
        int v = qt.top().second.second;
        int wt = qt.top().first;
        qt.pop();

        if (ds->find_ultimate_parent(u) != ds->find_ultimate_parent(v))
        {
            sum = sum + wt;
            ans.push_back(make_pair(make_pair(u, v), wt));
            ds->Union_by_Size(u, v);
        }
    }

    return ans;
}
