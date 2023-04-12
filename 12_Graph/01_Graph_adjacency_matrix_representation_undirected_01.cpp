// Undirected graph
// 1 based indexing

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n + 1][n + 1]; // 1 based indexing

    // Entering Edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // this statement will be removed in case of directed graph
    }

    // Printing Edges
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == 1)
                cout << i << "->" << j << endl;
        }
    }
    return 0;
}

//   1-----------2 \
//   | \         |   \
//   |    \      |     5
//   |       \   |   /
//   3-----------4 /

// -> Input
// 5
// 7
// 1 2
// 2 4
// 4 1
// 3 4
// 3 1
// 5 2
// 4 5

// -> Output
// 1->2
// 1->3
// 1->4
// 2->1
// 2->4
// 2->5
// 3->1
// 3->4
// 4->1
// 4->2
// 4->3
// 4->5
// 5->2
// 5->4