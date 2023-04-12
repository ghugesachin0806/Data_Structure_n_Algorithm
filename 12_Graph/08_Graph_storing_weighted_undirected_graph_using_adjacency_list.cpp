// Undirected graph
// 1 based indexing

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj_list[], int u, int v, int wt)
{
    adj_list[u].push_back(make_pair(v, wt));
    adj_list[v].push_back(make_pair(u, wt));
}

void printEdges(vector<pair<int, int>> adj_list[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj_list[i].size(); j++)
            cout << adj_list[i][j].first << "(" << adj_list[i][j].second << ")"
                 << ",";
        cout << endl;
    }
}

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;

    // Adjacency list
    vector<pair<int, int>> adj_list[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        addEdge(adj_list, u, v, wt);
    }

    cout << "Undirected weighted edges" << endl;
    printEdges(adj_list, n);

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
// 4->2(8),3(3),5(20),1(9),
// 5->4(20),2(11),