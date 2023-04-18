// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;

        st.insert(make_pair(0, S));
        dist[S] = 0;

        while (!st.empty())
        {
            auto temp = st.begin();

            int node = temp->second;
            int node_dist = temp->first;
            st.erase(temp);

            for (auto it : adj[node])
            {
                int trav_node = it[0];
                int trav_dist = it[1];

                if (node_dist + trav_dist < dist[trav_node])
                {
                    dist[trav_node] = node_dist + trav_dist;
                    st.insert(make_pair(dist[trav_node], trav_node));
                }
            }
        }

        return dist;
    }
};

// time complexity -> E log(V)
// E -> No. of Edges
// V -> No. of vertices