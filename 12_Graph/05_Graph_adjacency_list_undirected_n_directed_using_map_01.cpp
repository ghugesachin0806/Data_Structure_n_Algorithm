#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    T n;
    T m;
    bool directed;
    unordered_map<T, list<T>> adj_list;

    graph(T n, T m, bool b)
    {
        this->n = n;
        this->m = m;
        this->directed = b;
    }

    void addEdge(T u, T v)
    {
        adj_list[u].push_back(v);
        if (!directed)
            adj_list[v].push_back(u);
    }

    void printAdj_list()
    {
        for (auto temp : adj_list)
        {
            cout << temp.first << "->";
            for (auto inner : temp.second)
                cout << inner << " ,";

            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    // n-> Number of nodes
    // m-> Number of edges
    cin >> n >> m;

    /////////////////////// undirected n directed //////////////////////////////////////////
    graph<int> *g1 = new graph(n, m, false); // false ->undirected
    graph<int> *g2 = new graph(n, m, true);  // true ->directed

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g1->addEdge(u, v);
        g2->addEdge(u, v);
    }

    cout << "undirected output" << endl;
    g1->printAdj_list();

    cout << "directed output" << endl;
    g2->printAdj_list();

    return 0;
}

// ->Input
// 5 7
// 1 3
// 1 2
// 3 2
// 4 2
// 4 3
// 4 5
// 5 2

// undirected output
// 5->4 ,2 ,
// 4->2 ,3 ,5 ,
// 2->1 ,3 ,4 ,5 ,
// 3->1 ,2 ,4 ,
// 1->3 ,2 ,

// directed output
// 5->2 ,
// 4->2 ,3 ,5 ,
// 3->2 ,
// 1->3 ,2 ,