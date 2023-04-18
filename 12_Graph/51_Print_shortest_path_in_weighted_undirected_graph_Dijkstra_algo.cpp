// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qt;
    }
};