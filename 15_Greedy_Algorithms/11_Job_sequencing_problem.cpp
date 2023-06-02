// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comparator); // sort the array in increasing order of profit

        int max_deadslot = INT_MIN;

        int profit = 0;
        int total_jobs = 0;

        // slots for jobs
        vector<bool> slot(n, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead - 1; j >= 0; j--)
            {
                if (slot[j] == false)
                {
                    profit = profit + arr[i].profit;
                    slot[j] = true;
                    total_jobs++;
                    break;
                }
            }
        }

        vector<int> ans;
        ans.push_back(total_jobs);
        ans.push_back(profit);

        return ans;
    }
};