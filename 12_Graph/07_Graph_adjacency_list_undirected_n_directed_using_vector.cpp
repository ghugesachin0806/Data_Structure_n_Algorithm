#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // n-> Number of nodes
    // m-> Number of edges

    // it is array of vectors
    vector<int> adj_list1[n + 1];
    vector<int> adj_list2[n + 1];

    // vector<vector<int>> adj_list1(n + 1, vector<int>(n + 1));
    // vector<vector<int>> adj_list2(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // undirected edges
        adj_list1[u].push_back(v);
        adj_list1[v].push_back(u);

        // directed edges
        adj_list2[u].push_back(v);
    }

    // undirected graph
    cout << "undirected output" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj_list1[i].size(); j++)
            cout << adj_list1[i][j] << ",";

        cout << endl;
    }

    // directed graph
    cout << "directed output" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj_list2[i].size(); j++)
            cout << adj_list2[i][j] << ",";

        cout << endl;
    }

    return 0;
}

// 5 7
// 1 3
// 1 2
// 3 2
// 4 2
// 4 3
// 4 5
// 5 2

// undirected output
// 1->3,2,
// 2->1,3,4,5,
// 3->1,2,4,
// 4->2,3,5,
// 5->4,2,

// directed output
// 1->3,2,
// 2->
// 3->2,
// 4->2,3,5,
// 5->2,