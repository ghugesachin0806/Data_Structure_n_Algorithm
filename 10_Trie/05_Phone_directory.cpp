// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

#include <bits/stdc++.h>
using namespace std;

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
    /////////////////////////////////////////////////////////////////////////
    void find_sugg(Trie *root, vector<string> &vect, string prefix)
    {
        if (root->isTerminal)
            vect.push_back(prefix);

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                string temp = prefix;
                temp.push_back(root->children[i]->data);
                find_sugg(root->children[i], vect, temp);
            }
        }
    }

    vector<vector<string>> solve(string str)
    {
        string prefix = "";
        vector<vector<string>> ans;
        Trie *curr = root;

        for (int i = 0; i < str.size(); i++)
        {
            prefix.push_back(str[i]);

            int index = str[i] - 'a';

            if (curr->children[index])
            {
                vector<string> vect;
                find_sugg(curr->children[index], vect, prefix);

                ans.push_back(vect);
                curr = curr->children[index];
                vect.clear();
            }
            else
                break;
        }

        for (int i = prefix.size(); i <= str.size(); i++)
        {
            vector<string> vect;
            vect.push_back("0");
            ans.push_back(vect);
            vect.clear();
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie *t = new Trie();
        for (int i = 0; i < n; i++)
        {
            t->insert(contact[i]);
        }

        return t->solve(s);
    }
};