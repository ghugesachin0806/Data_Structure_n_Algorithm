#include <bits/stdc++.h>
using namespace std;

// assumption that all words in capital letters

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

        int index = word[0] - 'A';
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

    // Insertion operation
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

        int index = word[0] - 'A';

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

    ////////////////////////////////////////////// Remove ////////////////////////////////////////////////

    void removeUtil(Trie *&root, string word)
    {
        if (word.size() != 0)
        {
            int index = word[0] - 'A';
            removeUtil(root->children[index], word.substr(1));
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
                cnt++;
        }

        if (cnt == 0 && root->data != '\0')
        {
            if ((word.size() == 0 && root->isTerminal) || (word.size() != 0 && !root->isTerminal))
            {
                delete root;
                root = NULL;
            }
        }
        else if (word.size() == 0 && root->isTerminal)
        {
            root->isTerminal = false;
        }

        return;
    }

    void remove(string word)
    {
        if (search(word))
        {
            removeUtil(root, word);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
};

int main()
{
    Trie *t = new Trie();

    t->insert("TIME");
    t->insert("TIM");
    cout << t->search("TIME") << endl;
    cout << t->search("TIM") << endl;

    t->remove("TIME");
    cout << t->search("TIME") << endl;
    cout << t->search("TIM") << endl;

    ////////////////////////////////////////////////////////

    t->insert("TIME");
    t->insert("TIM");

    cout << t->search("TIME") << endl;
    cout << t->search("TIM") << endl;

    t->remove("TIM");
    cout << t->search("TIME") << endl;
    cout << t->search("TIM") << endl;

    return 0;
}

// 1
// 1
// 0
// 1
// 1
// 1
// 1
// 0