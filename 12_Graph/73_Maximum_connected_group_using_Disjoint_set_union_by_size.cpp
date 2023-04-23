// https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

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
    int change_index(Disjoint ds, vector<vector<int>> grid, vector<vector<int>> &nodes, int i, int j)
    {
        int maxi = 0;
        int row = grid.size();
        int col = grid[0].size();

        grid[i][j] = 1;

        int del_x[] = {0, 0, -1, +1};
        int del_y[] = {-1, +1, 0, 0};

        for (int del = 0; del < 4; del++)
        {
            int temp_x = i + del_x[del];
            int temp_y = j + del_y[del];

            if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col && grid[temp_x][temp_y] == 1)
            {
                if (ds.find_ultimate_parent(nodes[temp_x][temp_y]) != ds.find_ultimate_parent(nodes[i][j]))
                {
                    ds.Union_by_Size(nodes[temp_x][temp_y], nodes[i][j]);

                    if (ds.size[ds.find_ultimate_parent(nodes[i][j])] > maxi)
                    {
                        maxi = ds.size[ds.find_ultimate_parent(nodes[i][j])];
                    }
                }
            }
        }
        return maxi;
    }
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> nodes(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                nodes[i][j] = (i * row + j);
            }
        }

        int maxi = 1;
        Disjoint ds(row * col);

        int del_x[] = {0, 0, -1, +1};
        int del_y[] = {-1, +1, 0, 0};

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int del = 0; del < 4; del++)
                    {
                        int temp_x = i + del_x[del];
                        int temp_y = j + del_y[del];

                        if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col && grid[temp_x][temp_y] == 1)
                        {
                            if (ds.find_ultimate_parent(nodes[temp_x][temp_y]) != ds.find_ultimate_parent(nodes[i][j]))
                            {
                                ds.Union_by_Size(nodes[temp_x][temp_y], nodes[i][j]);

                                if (ds.size[ds.find_ultimate_parent(nodes[i][j])] > maxi)
                                {
                                    maxi = ds.size[ds.find_ultimate_parent(nodes[i][j])];
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 0)
                {
                    int temp = change_index(ds, grid, nodes, i, j);

                    if (temp > maxi)
                        maxi = temp;
                }
            }
        }

        return maxi;
    }
};
