// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

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
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        vector<int> vect;
        priority_queue<info *, vector<info *>, compare> minheap;

        for (int i = 0; i < K; i++)
        {
            info *temp = new info(arr[i][0], i, 0);

            minheap.push(temp);
        }

        while (minheap.size() > 0)
        {
            vect.push_back(minheap.top()->data);

            info *temp = minheap.top();
            minheap.pop();

            if (temp->col + 1 < arr[temp->row].size())
            {
                info *curr = new info(arr[temp->row][temp->col + 1], temp->row, temp->col + 1);
                minheap.push(curr);
            }
        }

        return vect;
    }
};