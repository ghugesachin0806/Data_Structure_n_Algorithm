// https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977

#include <bits/stdc++.h>
using namespace std;

// Here 1 based indexing is used as per question

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // distance vector
    vector<int> dist(n + 1, 1e9);

    dist[src] = 0;
    // n-1 relaxation iteration to get all sortest distace from source
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e9 && (dist[u] + wt) < dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }

    return dist[dest];
}