// https://practice.geeksforgeeks.org/problems/number-of-islands/1
// https://www.codingninjas.com/codestudio/problems/number-of-islands-ii_1266048
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        int row = n;
        int col = m;

        vector<vector<int>> nodes(row, vector<int>(col, 0));
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                nodes[i][j] = (i * col + j);
            }
        }

        int cnt = 0;
        int del_x[] = {-1, +1, 0, 0};
        int del_y[] = {0, 0, -1, +1};

        Disjoint *ds = new Disjoint(row * col);

        vector<int> ans;

        for (auto it : operators)
        {
            int x = it[0];
            int y = it[1];

            if (visited[x][y] == 0)
            {
                visited[x][y] = 1;
                cnt++;

                for (int i = 0; i < 4; i++)
                {
                    int temp_x = x + del_x[i];
                    int temp_y = y + del_y[i];

                    if (temp_x < row && temp_x >= 0 && temp_y < col && temp_y >= 0 && visited[temp_x][temp_y] == 1)
                    {
                        if (ds->find_ultimate_parent(nodes[x][y]) != ds->find_ultimate_parent(nodes[temp_x][temp_y]))
                        {
                            ds->Union_by_Size(nodes[x][y], nodes[temp_x][temp_y]);
                            cnt--;
                        }
                    }
                }
                ans.push_back(cnt);
            }
            else
            {
                ans.push_back(cnt);
            }
        }

        return ans;
    }
};
