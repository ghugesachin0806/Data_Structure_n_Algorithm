
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

int main()
{
    Disjoint *ds = new Disjoint(7);

    // connecting edges
    ds->Union_by_Size(1, 2);
    ds->Union_by_Size(2, 3);
    ds->Union_by_Size(4, 5);
    ds->Union_by_Size(6, 7);

    if (ds->find_ultimate_parent(5) == ds->find_ultimate_parent(6))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    ds->Union_by_Size(5, 6);

    if (ds->find_ultimate_parent(6) == ds->find_ultimate_parent(3))
        cout << "connected" << endl;
    else
        cout << "Not-connected" << endl;

    ds->Union_by_Size(4, 2);

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