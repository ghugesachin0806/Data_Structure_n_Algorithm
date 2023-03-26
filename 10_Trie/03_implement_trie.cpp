// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    char data;
    Trie *root;
    Trie *children[26];
    bool isTerminal;

    Trie()
    {
        this->data = '\0';
        this->isTerminal = false;
        this->root = this;

        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }

    Trie(char data)
    {
        this->data = data;
        this->isTerminal = false;
        this->root = this;

        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }
    /////////////////////////////////////// Insertion ///////////////////////////////////////////////////
    void insertUtil(Trie *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        Trie *child;

        // Present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // Absent
        else
        {
            child = new Trie(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    //////////////////////////////////////// Search /////////////////////////////////////////////////////

    bool searchUtil(Trie *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {
            return searchUtil(root->children[index], word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
    ///////////////////////////// startWith ///////////////////////////////////////////

    bool startwithUtil(Trie *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {
            return startwithUtil(root->children[index], word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool startsWith(string prefix)
    {
        return startwithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */