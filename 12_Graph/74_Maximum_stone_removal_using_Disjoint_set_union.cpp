// https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1\

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
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // To find row and col
        int row = 0;
        int col = 0;

        for (auto it : stones)
        {
            row = max(row, it[0]);
            col = max(col, it[1]);
        }

        row++;
        col++;

        Disjoint *ds = new Disjoint(col + row);

        for (auto it : stones)
        {
            int stone_x = it[0];
            int stone_y = it[1];

            int temp_x = stone_x;
            int temp_y = row + stone_y;

            ds->Union_by_Size(temp_x, temp_y);
        }

        set<int> st;
        for (int i = 0; i < row + col; i++)
        {
            int temp = ds->find_ultimate_parent(i);
            if (ds->size[temp] > 1)
                st.insert(temp);
        }

        int total_stones_removed = n - st.size();

        return total_stones_removed;
    }
};