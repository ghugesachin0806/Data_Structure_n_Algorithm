// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        queue<pair<int, int>> qt;
        vector<int> min_step(100000, INT_MAX);

        qt.push({0, start});
        min_step[start] = 0;

        while (!qt.empty())
        {
            int node_step = qt.front().first;
            int node = qt.front().second;
            qt.pop();

            for (int i = 0; i < arr.size(); i++)
            {
                int curr_node = (node * arr[i]) % 100000;
                int curr_step = node_step + 1;

                if (min_step[curr_node] > curr_step)
                {
                    min_step[curr_node] = curr_step;
                    qt.push(make_pair(curr_step, curr_node));

                    if (curr_node == end)
                        return curr_step;
                }
            }
        }

        return -1;
    }
};