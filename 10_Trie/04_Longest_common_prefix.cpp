// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////// optimized solution ////////////////////////////////////////////////////

class Trie
{
public:
    char data;
    Trie *children[26];
    Trie *root;
    bool isTerminal;

    Trie()
    {
        this->data = '\0';
        isTerminal = false;
        this->root = this;

        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }

    Trie(char data)
    {
        this->data = data;
        isTerminal = false;
        this->root = this;

        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }

    void insertUtil(Trie *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {
            insertUtil(root->children[index], word.substr(1));
        }
        else
        {
            Trie *child = new Trie(word[0]);
            root->children[index] = child;
            insertUtil(root->children[index], word.substr(1));
        }
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    void prefix(Trie *root, string &str)
    {
        if (root->isTerminal)
            return;

        int cnt = 0;
        Trie *curr = NULL;

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                curr = root->children[i];
                cnt++;
            }
        }

        if (cnt == 1)
        {
            str += curr->data;
            prefix(curr, str);
            return;
        }
        else
            return;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie *t = new Trie();

        for (int i = 0; i < strs.size(); i++)
        {
            t->insert(strs[i]);
        }

        string str = "";
        t->prefix(t->root, str);
        return str;
    }
};

///////////////////////////////////////// O(n^2) solution /////////////////////////////////////////////////

// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {

//         string ans = "";

//         for (int i = 0; i < strs[0].size(); i++)
//         {
//             char ch = strs[0][i];

//             for (int j = 1; j < strs.size(); j++)
//             {
//                 if (strs[j].size() <= i || ch != strs[j][i])
//                 {
//                     return ans;
//                 }
//             }
//             ans += ch;
//         }

//         return ans;
//     }
// };
