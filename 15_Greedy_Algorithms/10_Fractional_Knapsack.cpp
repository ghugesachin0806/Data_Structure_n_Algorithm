// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// class implemented
struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool comparator(pair<double, Item> pt1, pair<double, Item> pt2)
    {
        return pt1.first > pt2.first;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, Item>> vect;

        for (int i = 0; i < n; i++)
        {
            double perunit_val = (1.0 * arr[i].value / arr[i].weight);
            pair<double, Item> pt = make_pair(perunit_val, arr[i]);

            vect.push_back(pt);
        }

        sort(vect.begin(), vect.end(), comparator);

        double total_val = 0;

        for (int i = 0; i < n; i++)
        {
            if (W < vect[i].second.weight)
            {
                total_val = total_val + W * vect[i].first;
                W = 0;
            }
            else
            {
                total_val = total_val + vect[i].second.value;
                W = W - vect[i].second.weight;
            }
        }

        return total_val;
    }
};
