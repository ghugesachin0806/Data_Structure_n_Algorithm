// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(3, 0);

    for (int i = 0; i < 3; i++)
    {
        prev[i] = points[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(3, 0);
        for (int j = 0; j < 3; j++)
        {
            int maxi = INT_MIN;

            for (int k = 0; k < 3; k++)
            {
                if (j != k)
                {
                    maxi = max(maxi, prev[k]);
                }
            }

            curr[j] = maxi;
        }
        for (int temp = 0; temp < 3; temp++)
        {
            prev[temp] = curr[temp] + points[i][temp];
        }
    }

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        maxi = max(maxi, prev[i]);
    }

    return maxi;
}