// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool soln(int mid, int days, vector<int> weights)
    {
        int temp = 0;
        int cnt = 1;

        for (int i = 0; i < weights.size(); i++)
        {
            if (temp + weights[i] <= mid)
            {
                temp += weights[i];
            }
            else
            {
                cnt++;
                if (cnt > days || weights[i] > mid)
                    return false;

                temp = weights[i];
            }
        }

        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {

        int sum = 0;
        for (auto it : weights)
            sum += it;

        int start = 0;
        int end = sum;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (soln(mid, days, weights))
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};