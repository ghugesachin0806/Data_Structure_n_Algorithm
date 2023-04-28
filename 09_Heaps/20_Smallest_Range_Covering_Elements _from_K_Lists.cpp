// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <bits/stdc++.h>
using namespace std;

class info
{
public:
    int data;
    int row;
    int col;

    info(int data, int row, int col)
    {
        this->data = data;
        this->col = col;
        this->row = row;
    }
};

class compare
{
public:
    bool operator()(info *a, info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> vect = {-1, -1};
        int ans = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<info *, vector<info *>, compare> qt;

        for (int i = 0; i < nums.size(); i++)
        {
            info *temp = new info(nums[i][0], i, 0);
            qt.push(temp);

            if (maxi < nums[i][0])
                maxi = nums[i][0];
        }

        info *temp = qt.top();

        while (1)
        {
            if (ans > maxi - temp->data)
            {
                vect[0] = temp->data;
                vect[1] = maxi;
                ans = vect[1] - vect[0];
            }

            if (temp->col + 1 == nums[temp->row].size())
                break;

            info *curr = new info(nums[temp->row][temp->col + 1], temp->row, temp->col + 1);
            if (curr->data > maxi)
                maxi = curr->data;

            qt.pop();
            qt.push(curr);

            temp = qt.top();
        }
        return vect;
    }
};