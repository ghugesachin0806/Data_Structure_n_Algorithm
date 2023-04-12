#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;

    // undirected graph
    unordered_map<int, list<int>> adj_list1;
    // directed graph
    unordered_map<int, list<int>> adj_list2;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // undirected edge input
        adj_list1[u].push_back(v);
        adj_list1[v].push_back(u);

        // directed edge input
        adj_list2[u].push_back(v);
    }

    cout << "undirected output" << endl;
    for (auto temp : adj_list1)
    {
        cout << temp.first << "->";
        for (auto inner : temp.second)
            cout << inner << ",";

        cout << endl;
    }

    cout << "directed output" << endl;
    for (auto temp : adj_list2)
    {
        cout << temp.first << "->";
        for (auto inner : temp.second)
            cout << inner << ",";

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
// 5->4,2,
// 4->2,3,5,
// 2->1,3,4,5,
// 3->1,2,4,
// 1->3,2,

// directed output
// 5->2,
// 4->2,3,5,
// 3->2,
// 1->3,2,