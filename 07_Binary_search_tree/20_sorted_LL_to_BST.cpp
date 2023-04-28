// https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1

#include <bits/stdc++.h>
using namespace std;

// Linked List
struct LNode
{
    int data;
    struct LNode *next;

    LNode(int x)
    {
        data = x;
        next = NULL;
    }
};

// Tree
struct TNode
{

    int data;
    struct TNode *left;
    struct TNode *right;
    TNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution
{
public:
    // sachin ghuge
    int cnt(LNode *head)
    {
        int temp = 0;
        while (head)
        {
            temp++;
            head = head->next;
        }

        return temp;
    }

    TNode *LL_BST(LNode *head)
    {
        if (head == NULL)
            return NULL;

        int n = cnt(head);

        int mid;

        if (n % 2 == 1)
            mid = n - (n / 2);
        else
            mid = n + 1 - (n / 2);

        int k = 1;

        LNode *temp = head;
        LNode *prev = NULL;

        while (k != mid)
        {
            prev = temp;
            temp = temp->next;
            k++;
        }

        LNode *Lnext = temp->next;

        if (prev)
            prev->next = NULL;

        TNode *curr = new TNode(temp->data);

        if (prev)
            curr->left = LL_BST(head);
        else
            curr->left = NULL;

        curr->right = LL_BST(Lnext);

        return curr;
    }

    TNode *sortedListToBST(LNode *head)
    {
        // code here
        return LL_BST(head);
    }
};