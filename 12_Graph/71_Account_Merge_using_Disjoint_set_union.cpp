// https://leetcode.com/problems/accounts-merge/
// https://practice.geeksforgeeks.org/problems/account-merge/1

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mt;

        Disjoint *ds = new Disjoint(accounts.size());

        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mt.find(accounts[i][j]) == mt.end())
                {
                    mt[accounts[i][j]] = i;
                }
                else
                {
                    ds->Union_by_Size(i, mt[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> vect(accounts.size(), vector<string>());

        for (auto it : mt)
        {
            int ult_p = ds->find_ultimate_parent(it.second);
            vect[ult_p].push_back(it.first);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (vect[i].size() == 0)
                continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            sort(vect[i].begin(), vect[i].end());

            for (auto it : vect[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};