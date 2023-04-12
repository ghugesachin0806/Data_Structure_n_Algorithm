// directed graph
// 1 based indexing
#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int n;
    int m;
    bool directed;
    vector<vector<int>> adj_matrix;

    // constructor
    graph(int n, int m, bool b)
    {
        this->n = n;
        this->m = m;
        this->directed = b;

        vector<vector<int>> temp(n + 1, vector<int>(n + 1)); // 1 based indexing
        adj_matrix = temp;

        temp.clear();
    }

    void addedge(int u, int v)
    {
        adj_matrix[u][v] = 1;

        if (!directed)
            adj_matrix[v][u] = 1;
    }

    void print_graph()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_matrix[i][j])
                {
                    cout << i << "->" << j << endl;
                }
            }
        }
    }
};

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;

    graph *g = new graph(n, m, true); // true -> directed

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g->addedge(u, v);
    }

    g->print_graph();

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

// ->Output
// 1->2
// 2->4
// 3->1
// 3->4
// 4->1
// 4->5
// 5->2