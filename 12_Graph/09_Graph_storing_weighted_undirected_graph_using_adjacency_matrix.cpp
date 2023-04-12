#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adj_matrix, int u, int v, int wt)
{
    adj_matrix[u][v] = wt;
    adj_matrix[v][u] = wt;
}

void printEdges(vector<vector<int>> &adj_matrix)
{
    for (int i = 1; i < adj_matrix.size(); i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj_matrix[i].size(); j++)
        {
            if (adj_matrix[i][j] > 0)
                cout << j << "(" << adj_matrix[i][j] << ")"
                     << ",";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;

    // Adjacency matrix
    vector<vector<int>> adj_matrix(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdges(adj_matrix, u, v, wt);
    }

    cout << "Undirected weighted edges" << endl;
    printEdges(adj_matrix);
    return 0;
}

// 5 7
// 1 2 7 
// 2 4 8 
// 3 1 5 
// 4 3 3 
// 4 5 20
// 4 1 9 
// 5 2 11

// Undirected weighted edges
// 1->2(7),3(5),4(9),       
// 2->1(7),4(8),5(11),
// 3->1(5),4(3),
// 4->1(9),2(8),3(3),5(20),
// 5->2(11),4(20),