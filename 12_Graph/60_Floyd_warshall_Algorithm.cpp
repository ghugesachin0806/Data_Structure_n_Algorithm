// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // no. of nodes
        int n = matrix.size();

        // converting -1 to INT_MAX
        // coverting all diagonals to 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = INT_MAX;

                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        // Going via every node to compute shortest distance matrix
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX)
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////

        // Detecting negative cycle in graph using Floyd warshall algo
        // for(int i=0;i<n;i++)
        // {
        //     if(matrix[i][i]<0)
        //     {
        //         cout<<"negative cycle is present in graph"<<endl;
        //     }
        // }

        ////////////////////////////////////////////////////////////////////////////////////////////////

        // converting INT_MAX to -1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == INT_MAX)
                    matrix[i][j] = -1;
            }
        }
    }
};