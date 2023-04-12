// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> vect(n);
    for (int i = 0; i < n; i++)
        vect[i].push_back(i);

    for (int i = 0; i < m; i++)
    {
        vect[edges[i][0]].push_back(edges[i][1]);
        vect[edges[i][1]].push_back(edges[i][0]);
    }
    return vect;
}