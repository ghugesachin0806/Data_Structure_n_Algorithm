// directed graph
// 1 based indexing
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;
    // time complexity: O(n)
    int adj[n + 1][n + 1]; // 1 based indexing

    // Entering edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
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
// 2->4
// 3->1
// 3->4
// 4->1
// 4->5
// 5->2