// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        vector<int> vect = {-1, -1};
        int cnt = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                cnt = mid;
                break;
            }

            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        if (cnt == -1)
            return vect;
        else
        {
            vect[0] = cnt;
            vect[1] = cnt;

            while (vect[0] > 0 && nums[vect[0] - 1] == target)
            {
                vect[0]--;
            }

            while (vect[1] < nums.size() - 1 && nums[vect[1] + 1] == target)
            {
                vect[1]++;
            }

            return vect;
        }
    }
};