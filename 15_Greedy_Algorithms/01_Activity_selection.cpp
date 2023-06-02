// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of activities that can be performed by a single person.
    static bool cmd(pair<int, int> pt1, pair<int, int> pt2)
    {
        return pt1.second < pt2.second; // For ascending order
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> vect;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> pt = make_pair(start[i], end[i]);
            vect.push_back(pt);
        }

        // Sort according to end time
        sort(vect.begin(), vect.end(), cmd);

        int end_time = vect[0].second;
        int cnt = 1;

        for (int i = 1; i < n; i++)
        {
            if (vect[i].first > end_time)
            {
                cnt++;
                end_time = vect[i].second;
            }
        }

        return cnt;
    }
};