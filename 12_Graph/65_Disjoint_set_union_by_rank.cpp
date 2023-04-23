
#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
private:
    vector<int> rank;
    vector<int> parent;

public:
    // constructor
    // n is no. of nodes in the graph
    Disjoint(int n)
    {
        // below defined vector size can be used for 0 or 1 based indexing
        rank.resize(n + 1, 0);
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

    void Union_by_Rank(int u, int v)
    {
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] == rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_v] > rank[ulp_u])
        {
            parent[ulp_u] = ulp_v;
        }
    }
};

int main()
{
    Disjoint *ds = new Disjoint(7);

    // connecting edges
    ds->Union_by_Rank(1, 2);
    ds->Union_by_Rank(2, 3);
    ds->Union_by_Rank(4, 5);
    ds->Union_by_Rank(6, 7);

    if (ds->find_ultimate_parent(5) == ds->find_ultimate_parent(6))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    ds->Union_by_Rank(5, 6);

    if (ds->find_ultimate_parent(6) == ds->find_ultimate_parent(3))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    ds->Union_by_Rank(4, 2);

    if (ds->find_ultimate_parent(6) == ds->find_ultimate_parent(3))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    if (ds->find_ultimate_parent(1) == ds->find_ultimate_parent(7))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    if (ds->find_ultimate_parent(0) == ds->find_ultimate_parent(7))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    return 0;
}

// Not-connected
// Not-connected
// connected
// connected
// Not-connected
