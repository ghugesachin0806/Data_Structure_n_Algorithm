// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        if (nums.size() == 1 || nums[0] < nums[end])
            return solve(nums, start, end, target);
        else
        {
            while (start < end)
            {
                int mid = start + (end - start) / 2;

                if (nums[mid] >= nums[0])
                    start = mid + 1;
                else
                    end = mid;
            }

            if (target >= nums[0])
                return solve(nums, 0, start - 1, target);
            else
                return solve(nums, start, nums.size() - 1, target);
        }
    }
};