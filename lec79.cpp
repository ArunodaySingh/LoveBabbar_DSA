// Trie Data Structure

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // TO give dynamic memory allocation
    bool isTerminal;
    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        // cout<<"i am calleld";
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Here assumntion CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // kuch to hai re baba
        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursion dekh lega
        return insertUtil(child, word.substr(1));
    }
    void inserWord(string word)
    {
        insertUtil(root, word);
    }
    int i = 0;
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool  deleteUtil(TrieNode *root, string word)
    {
        if(word.length()==0)
        {
            return root->isTerminal;
        }

        int index=word[0]-'A';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {  
          child=root->children[index];
          if(word.length()==1)
          {
            child->isTerminal=0;
            return 1;
          }
        }
        else
        {
            return root->isTerminal;
        }

        return deleteUtil(child,word.substr(1));
    }

    bool deleteWord(string word)
    {
        return deleteUtil(root, word);
    }
};

int main()
{
    Trie *obj = new Trie();
    obj->inserWord("ABCD");
    obj->inserWord("BCDEFGH");
    cout << obj->searchWord("BCDEFGH") << endl;
    cout<<obj->deleteWord("BCDEFGH")<<endl;
    cout << obj->searchWord("ABCD") << endl;
     cout<<obj->deleteWord("ABCD")<<endl;
     cout << obj->searchWord("ABCD") << endl;

    return 0;
}
