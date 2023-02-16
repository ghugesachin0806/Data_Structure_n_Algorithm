#include <bits/stdc++.h>
using namespace std; 

// Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> fast_diameter(Node* root)
    {
        if(root==NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> cnt1 = fast_diameter(root->left);
        pair<int,int> cnt2 = fast_diameter(root->right);
        int cnt4 = max((cnt1.first+cnt2.first+1),max(cnt2.second,cnt1.second));
        pair<int,int> cnt3 = make_pair(max(cnt1.first+1,cnt2.first+1),cnt4);

        return cnt3;

    }
    int diameter(Node* root) {
        // Your code here

        pair<int,int> pt = fast_diameter(root);

        return pt.second;
    }
};
